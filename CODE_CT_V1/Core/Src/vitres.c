#include "vitres.h"
#include "main.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal_gpio.h"

// On récupère le tableau rempli automatiquement par le DMA (depuis main.c)
extern uint16_t adc_buffer[5]; 
// Rappel de tes rangs CubeMX :
// adc_buffer[0] -> IN0 (Tablette)
// adc_buffer[1] -> IN1 (Température)
// adc_buffer[2] -> IN2 (Courant 1 / Shunt_1 et 2)
// adc_buffer[3] -> IN3 (Courant 2 / Shunt_3 et 4)
// adc_buffer[4] -> IN16 (Température interne du MCU)

static SequenceVitre_t seqGauche = SEQ_ARRET;

// Variables pour mémoriser l'état de la séquence en cours
static uint32_t timerDebutMouvement = 0;
static uint8_t modeAutomatiqueEnCours = 0; // 1 = Auto, 0 = Manuel

static CmdBouton_t LireBoutonGauche(void) {
    // Cette fonction sera à adapter avec ta vraie matrice de boutons
    if (HAL_GPIO_ReadPin(IN_VITRE_3_GPIO_Port, IN_VITRE_3_Pin) == GPIO_PIN_SET) return CMD_MONTE_AUTO;
    if (HAL_GPIO_ReadPin(IN_VITRE_1_GPIO_Port, IN_VITRE_1_Pin) == GPIO_PIN_SET) return CMD_MONTE;
    if (HAL_GPIO_ReadPin(IN_VITRE_4_GPIO_Port, IN_VITRE_4_Pin) == GPIO_PIN_SET) return CMD_DESC_AUTO;
    if (HAL_GPIO_ReadPin(IN_VITRE_2_GPIO_Port, IN_VITRE_2_Pin) == GPIO_PIN_SET) return CMD_DESC;
    
    return CMD_REPOS;
}

/**
 * @brief Sécurité globale : Vérifie la butée ET le temps de fonctionnement
 * @return 1 si on doit couper le moteur, 0 si on peut continuer
 */
static uint8_t MoteurDoitSArreter(void) {
    uint32_t tempsEcoule = osKernelGetTickCount() - timerDebutMouvement;

    // SÉCURITÉ 1 : Le moteur tourne depuis trop longtemps (ex: 6 secondes)
    if (tempsEcoule > TIMEOUT_MOTEUR_MS) {
        return 1; // STOP URGENCE
    }

    // SÉCURITÉ 2 : Masquage du courant de démarrage (Inrush)
    if (tempsEcoule < TEMPS_INRUSH_MS) {
        return 0; // On ignore les pics de courant pendant les 300 premières ms
    }

    // SÉCURITÉ 3 : Détection de butée (Courant)
    if (adc_buffer[2] > SEUIL_COURANT_BUTEE || adc_buffer[3] > SEUIL_COURANT_BUTEE) {
        return 1; // Le moteur force, on coupe
    }

    return 0; // Tout va bien, le moteur peut continuer de tourner
}

/**
 * @brief Machine à états SÉQUENTIELLE pour le côté Gauche
 */
static void PiloterSequenceGauche(CmdBouton_t cmd) {
    
    // --- GESTION DE L'ANNULATION ---
    // Si on est en mode AUTO, mais que le conducteur appuie dans le sens inverse,
    // on doit annuler la séquence immédiatement (Sécurité antipincement basique)
    if (modeAutomatiqueEnCours) {
        if ((seqGauche == SEQ_DESC_AVANT || seqGauche == SEQ_DESC_ARRIERE) && (cmd == CMD_MONTE || cmd == CMD_MONTE_AUTO)) {
            seqGauche = SEQ_ARRET;
        }
        if ((seqGauche == SEQ_MONTE_ARRIERE || seqGauche == SEQ_MONTE_AVANT) && (cmd == CMD_DESC || cmd == CMD_DESC_AUTO)) {
            seqGauche = SEQ_ARRET;
        }
    }

    // --- MACHINE À ÉTATS ---
    switch(seqGauche) {
        
        case SEQ_ARRET:
            // 1. On coupe tout (HAL_GPIO_WritePin ... RESET)
            modeAutomatiqueEnCours = 0;
            
            // 2. On attend un nouvel ordre
            if(cmd == CMD_DESC || cmd == CMD_DESC_AUTO) {
                if (cmd == CMD_DESC_AUTO) modeAutomatiqueEnCours = 1;
                timerDebutMouvement = osKernelGetTickCount(); // On lance le chrono !
                
                // ACTIVER_MOTEUR_AVANT_DESC;
                seqGauche = SEQ_DESC_AVANT;
            }
            else if(cmd == CMD_MONTE || cmd == CMD_MONTE_AUTO) {
                if (cmd == CMD_MONTE_AUTO) modeAutomatiqueEnCours = 1;
                timerDebutMouvement = osKernelGetTickCount(); // On lance le chrono !
                
                // ACTIVER_MOTEUR_ARRIERE_MONTE;
                seqGauche = SEQ_MONTE_ARRIERE;
            }
            break;

        case SEQ_DESC_AVANT:
            // Arrêt si bouton relâché (et qu'on n'est pas en auto)
            if(!modeAutomatiqueEnCours && cmd == CMD_REPOS) {
                seqGauche = SEQ_ARRET; 
            } 
            // Arrêt si butée ou timeout atteint
            else if(MoteurDoitSArreter()) {
                // COUPER_MOTEUR_AVANT;
                // ACTIVER_MOTEUR_ARRIERE_DESC;
                
                timerDebutMouvement = osKernelGetTickCount(); // On RAZ le chrono pour le 2ème moteur
                seqGauche = SEQ_DESC_ARRIERE;
            }
            break;

        case SEQ_DESC_ARRIERE:
            if(!modeAutomatiqueEnCours && cmd == CMD_REPOS) {
                seqGauche = SEQ_ARRET; 
            }
            else if(MoteurDoitSArreter()) {
                // Séquence terminée
                seqGauche = SEQ_ARRET;
            }
            break;

        case SEQ_MONTE_ARRIERE:
            if(!modeAutomatiqueEnCours && cmd == CMD_REPOS) {
                seqGauche = SEQ_ARRET; 
            } 
            else if(MoteurDoitSArreter()) {
                // COUPER_MOTEUR_ARRIERE;
                // ACTIVER_MOTEUR_AVANT_MONTE;
                
                timerDebutMouvement = osKernelGetTickCount(); // On RAZ le chrono pour le 2ème moteur
                seqGauche = SEQ_MONTE_AVANT;
            }
            break;

        case SEQ_MONTE_AVANT:
            if(!modeAutomatiqueEnCours && cmd == CMD_REPOS) {
                seqGauche = SEQ_ARRET; 
            }
            else if(MoteurDoitSArreter()) {
                // Séquence terminée
                seqGauche = SEQ_ARRET;
            }
            break;
        
        default:
            seqGauche = SEQ_ARRET;
            break;
    }
}

void Vitres_Process(void) {
    CmdBouton_t cmdG = LireBoutonGauche();
    PiloterSequenceGauche(cmdG);
}