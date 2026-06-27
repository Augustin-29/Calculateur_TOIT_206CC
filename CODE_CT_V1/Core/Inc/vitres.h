#ifndef VITRES_H
#define VITRES_H

// --- CONSTANTES DE SÉCURITÉ ---
#define SEUIL_COURANT_BUTEE    1000 // Valeur ADC pour ~10A
#define TEMPS_INRUSH_MS        300  // Temps ignoré au démarrage du moteur (ms)
#define TIMEOUT_MOTEUR_MS      6000 // Temps MAX de fonctionnement autorisé (ms)

// Les commandes physiques du bouton (Gauche ou Droite)
typedef enum {
    CMD_REPOS,
    CMD_MONTE,
    CMD_MONTE_AUTO,
    CMD_DESC,
    CMD_DESC_AUTO
} CmdBouton_t;

// La machine à états pour la séquence d'une vitre
typedef enum {
    SEQ_ARRET,
    SEQ_DESC_AVANT,
    SEQ_DESC_ARRIERE,
    SEQ_MONTE_ARRIERE,
    SEQ_MONTE_AVANT
} SequenceVitre_t;

void Vitres_Init(void);
void Vitres_Process(void);

#endif /* VITRES_H */