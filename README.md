# Gamelle Connectée

## 1) Introduction

**Le projet de la Gamelle Connectée**

Le projet que nous avons été amenés à créer durant la semaine de projet consiste à programmer un ESP8266 dans le but de créer une gamelle connectée. L'objectif principal est de commander deux servomoteurs à l'aide d'une interface web hébergée sur un serveur. De plus, l'ajout d'un capteur de pression permet de savoir s'il reste de la nourriture dans la gamelle. Pour une expérience utilisateur plus complète, des LEDs et un buzzer sont intégrés pour indiquer si tout s'est bien passé. Ce projet combine ainsi la programmation d'un microcontrôleur, l'utilisation de capteurs et la création d'une interface web pour un système complet et connecté.

![IMG_0161](https://github.com/CedricChnfr/Cpp_INSA/assets/127315734/61f2fb2e-68f8-45f4-853b-7f3fc1a3ea7b)

## 2) Interaction avec le Système

### Compiler le Projet et Utiliser la carte

Pour compiler le projet, assurez-vous d'avoir les outils de développement nécessaires installés sur votre environnement. Utilisez les commandes de compilation appropriées selon votre plateforme. 

- Sous Visual Studio Code vous pouvez appuyer sur le bouton suivant (ne pas cabler les composants lors du téléversement):
![image](https://github.com/CedricChnfr/Cpp_INSA/assets/127315734/3ca05922-6d51-4d6a-b79f-74983703ea7c)
- Une fois que le téléversement est réussi, débranchez l'ESP8266 de votre ordinateur et connectez-le à l'alimentation prévue sur le site d'installation.
- Cabler les composants à la carte ( Moteur 1: D6, Moteur 2: D1, Capteur : D7, Buzzer : D5, Led rouge: D8, Led verte: D4, Led jaune: D3)
- Ouvrir le site web avec l'adresse IP récupéré sur le port Série. S'assurer d'avoir connecté votre appareil au même réseau spécifié dans le code (WifiServer server(ssid, mot_de_passe);)

## 3) Utilisation

### Connexion au Serveur

Avant d'accéder à l'interface web, assurez-vous que votre ESP8266 est connecté au réseau. Vous pouvez obtenir l'adresse IP de votre ESP8266 en consultant le moniteur série ou en utilisant un outil de numérisation de réseau.

Une fois que vous avez l'adresse IP, ouvrez un navigateur web et entrez l'adresse dans la barre d'adresse.

### Interface Web

L'interface web vous permet de contrôler la distribution de nourriture pour deux compartiments distincts. Vous verrez deux boutons, un pour la nourriture 1 et l'autre pour la nourriture 2.

### Distribution de Nourriture

- **Choix 1 :** Lorsque vous sélectionnez "Nourriture 1", le servomoteur correspondant s'active, ouvrant la trappe du compartiment 1.

- **Choix 2 :** De même, en sélectionnant "Nourriture 2", le servomoteur associé ouvre la trappe du compartiment 2.
  ![image](https://github.com/CedricChnfr/Cpp_INSA/assets/127315734/8f31c5a8-85a4-4a0b-a9f6-69f54c26ebe8?raw=true)

### Détection de Nourriture

Le système intègre un capteur de pression pour détecter la présence de nourriture dans les compartiments. Si le capteur indique qu'il y a de la nourriture :

- La trappe correspondante s'ouvre comme prévu.
  
Si le capteur indique qu'il n'y a pas de nourriture :

- Un buzzer émet un son d'alerte.
- Une LED rouge s'allume pour signaler l'absence de nourriture.

Cette combinaison de commandes web, capteurs et indicateurs visuels rend la Gamelle Connectée intuitive et interactive.

## 4) Conclusion

Le projet de la Gamelle Connectée nous a permis de mettre en pratique plusieurs concepts et compétences clés en programmation embarquée et en développement web. Nous avons appris à interagir avec un microcontrôleur ESP8266, à concevoir une interface web pour le contrôler, et à intégrer des capteurs pour rendre le système plus intelligent.

Ce projet nous a également confrontés à des défis pratiques tels que la gestion des connexions WiFi, la manipulation des servomoteurs et la communication entre le microcontrôleur et l'interface web. En surmontant ces défis, nous avons acquis une expérience précieuse dans le développement d'applications IoT.

En conclusion, la Gamelle Connectée illustre l'application concrète de compétences polyvalentes dans le domaine de l'embarqué et du web, offrant une solution interactive et innovante pour la gestion de la nourriture pour animaux.
