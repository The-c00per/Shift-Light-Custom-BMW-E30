# 🏎️ BMW E30 Custom Shift-Light (ESP32)

![Languague](https://img.shields.io/badge/Language-Arduino%20/%20C++-blue)
![Hardware](https://img.shields.io/badge/Hardware-ESP32-orange)
![Car](https://img.shields.io/badge/Car-BMW%20E30-lightgrey)

## ✨ Présentation du Projet
Ce projet vise à intégrer un indicateur de changement de rapport (Shift-Light) personnalisé et moderne dans l'habitacle d'une **BMW E30**. Alimenté par un microcontrôleur **ESP32**, il interprète le signal de régime moteur (RPM) pour activer un ruban de 9 LED NeoPixel, offrant une indication visuelle claire et réactive.

Le boîtier est conçu pour s'intégrer discrètement ou de manière visible selon les préférences, en mettant en valeur le savoir-faire DIY (Do It Yourself) et la passion automobile.

## 🛠️ Schéma de Câblage Détaillé
Le circuit est conçu pour la robustesse en environnement automobile (12V) et la protection de l'ESP32 (3.3V).

### ⚡ Signal Moteur (12V vers 3.3V)
Un pont diviseur de tension (résistances 10kΩ et 4.7kΩ) est utilisé pour adapter le signal 12V de la bobine/calculateur de l'E30 à l'entrée GPIO 34 de l'ESP32. Cette étape est cruciale pour éviter d'endommager le microcontrôleur.

![Schéma de Câblage ESP32 & LED](images/wokwi_schema.png) 
_Vue du schéma de câblage principal avec l'ESP32, les résistances de protection et le ruban LED._

### 💡 Branchement des LED NeoPixel
Le ruban LED est connecté à l'ESP32 comme suit :
- **Fils Rouges (x2)**: Alimentation +5V (connectés à la broche 5V de l'ESP32).
- **Fils Blancs (x2)**: Masse (GND) (connectés à une broche GND de l'ESP32).
- **Fil Bleu-Vert**: Ligne de données (DIN) (connecté à la broche GPIO 2 de l'ESP32 via une résistance de protection de 330Ω).

## 🚀 Fonctionnement du Code
Le firmware de l'ESP32 utilise une interruption matérielle (`attachInterrupt`) pour un calcul précis et rapide du régime moteur (RPM).

### Paliers d'éclairage des LED :
Les 9 LED s'allument progressivement en fonction du RPM :
- **1200 - 4000 RPM (5 LED Vertes)** : Indication du régime de croisière et de chauffe.
- **4500 RPM (1 LED Jaune)** : Zone d'alerte, préparation au changement de rapport.
- **5000 - 6500 RPM (3 LED Rouges)** : Zone de puissance maximale et indication du régime optimal pour un passage de vitesse.

![Séquence d'allumage des LED](images/led_sequence.gif) 
_Exemple d'animation montrant la progression des couleurs en fonction du régime moteur._

### Mode "Rupteur" (Flash Stroboscopique)
Au-delà de **6600 RPM**, toutes les LED se mettent à flasher en rouge. Ceci sert d'alerte visuelle immédiate pour indiquer que le moteur atteint sa limite et qu'un changement de rapport est urgent.

## 📦 Boîtier Imprimé en 3D
Un boîtier sur mesure a été conçu pour accueillir le ruban LED et l'électronique. Imprimé en **ABS** (ou **ASA** pour une meilleure résistance à la chaleur), il garantit une intégration discrète et robuste dans l'habitacle de la BMW E30.

![Boîtier 3D et ruban LED](images/boitier_3d.png)
_Photo du boîtier imprimé en 3D avec les LED installées._

## 🚗 Installation dans la BMW E30
Le module est conçu pour être branché directement sur le faisceau électrique de la E30.
- **Alimentation de l'ESP32**: Utilisation d'un convertisseur DC-DC (Step-Down) 12V vers 5V pour alimenter l'ESP32 de manière stable à partir de la batterie du véhicule.
- **Connexion du signal RPM**: Le fil de signal RPM est généralement trouvé derrière le combiné d'instruments (souvent un fil **noir** ou **noir/bleu** sur le connecteur bleu à 26 broches).

![Installation finale dans l'E30](images/installation_e30.jpg)
_Image de l'intégration finale du Shift-Light dans l'habitacle de la BMW E30._


## 📚 Références et Sources techniques

Ce projet a été rendu possible grâce aux ressources documentaires de la communauté BMW E30 :

* **Schémas de câblage et Tests sur banc** : [Instructables - Bench Testing BMW E30 Tachometer](https://www.instructables.com/Bench-Testing-BMW-E30s-Tachometer/)
* **Inspiration Shift-Light** : [Instructables - BMW E30 Shift Light](https://www.instructables.com/BMW-E30s-Shift-Light/)

> *Note : Les images techniques et les numéros de pins (C1 Pin 7 pour le RPM) proviennent de la documentation technique officielle BMW et des guides communautaires cités ci-dessus.*

## 🤝 Contribution
N'hésitez pas à proposer des améliorations ou des modifications pour ce projet !

---
```http://googleusercontent.com/image_generation_content/0
