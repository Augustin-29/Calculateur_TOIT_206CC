# Calculateur TOIT 206CC (Version 1)

Ce projet open-source consiste en la rétro-ingénierie et la conception d'un calculateur de remplacement sur mesure pour la gestion du toit escamotable d'une Peugeot 206 CC. La V1 s'appuie sur une architecture matérielle moderne et un système d'exploitation temps réel pour piloter de manière fiable et sécurisée le cycle d'ouverture/fermeture du toit.

---

## 🛠️ Architecture du Projet

Le dépôt regroupe l'ensemble du projet dans une structure centralisée :
*   **`CAO/`** : Conception matérielle complète sous KiCad (Schématiques, empreintes spécifiques, modélisations 3D et fichiers de fabrication Gerber).
*   **`CODE_CT_V1/`** : Logiciel embarqué développé en C/C++ avec une structure de build basée sur CMake.

---

## 💾 Spécifications Techniques (Hardware)

Le module remplace l'électronique d'origine en modernisant la chaîne de traitement et de commande.

*   **Microcontrôleur principal** : STM32F103 (Cortex-M3), choisi pour sa gestion des périphériques et ses timers avancés nécessaires à l'acquisition des capteurs de position.
*   **Interface Véhicule & Diagnostic** : Support de la ligne K (K-line) pour la communication de diagnostic et l'analyse de protocole.
*   **Connectique d'Origine** : Intégration sur le PCB d'une empreinte sur mesure pour le connecteur jaune 26 broches spécifique au faisceau habitacle de la 206 CC.
*   **Routage & Puissance** : 
    *   Routage optimisé des pistes de puissance pour la gestion des courants des moteurs de pompe hydraulique et des actionneurs.
    *   Protection renforcée de l'étage d'alimentation face aux contraintes du réseau électrique automobile (transitoires, variations de tension).
    *   Isolation et conditionnement des signaux des micro-contacts (capteurs de fin de course des éléments du toit et du coffre).

---

## 💻 Logiciel Embarqué (Firmware)

Le code est architecturé pour garantir le déterminisme et la sécurité lors des mouvements mécaniques du toit.

*   **Système d'Exploitation** : Intégration de **FreeRTOS** pour orchestrer les tâches concurrentes (gestion de la machine d'état du toit, scrutation des capteurs, communications).
*   **Gestion de la Sécurité** : Tâches prioritaires surveillant en temps réel l'état des capteurs pour interrompre immédiatement le cycle en cas d'anomalie ou d'obstacle.
*   **Environnement de Développement** : Configuration complète sous **CMake**, facilitant la cross-compilation avec la chaîne d'outils `gcc-arm-none-eabi`.

---

## 📂 Contenu du dossier CAO

Le dossier de conception électronique inclut :
*   Le schéma structurel (`.kicad_sch`) et le routage du PCB (`.kicad_pcb`).
*   Les fichiers de fabrication indispensables (Générés dans `CAO/gerber/` : couches de cuivre, masques de soudure, sérigraphies et fichiers de perçage `.drl`).
*   Les modèles 3D des composants spécifiques (relais automobiles, connecteur jaune 26P, etc.) utilisés pour valider l'intégration mécanique de la carte dans son boîtier.

---

## 🚀 À venir (Roadmap V2)

*   Validation de la machine d'état sur banc de test et intégration véhicule.
*

---
*Projet développé par Augustin — 2026.*
