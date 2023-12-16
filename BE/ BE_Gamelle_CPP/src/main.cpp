#include "Wifi_Serveur.h"
#include "Servomotor.h"
#include "Alerte.h"
#include <iostream>
#include <vector>


WifiServer server("Livebox-8C50", "Chanfreaulafamille5");

// Pin pour les servos
const int brocheServoG = 12;  // D6
const int brocheServoD = 5;   // D1
// Pin pour le capteur de pression
const int brocheCapteur = 13; // D7
//Pin du buzzer
Buzzer monBuzzer(D5);         // D5
//Vecteur de LED
std::vector<LED> leds;

//Création des objets moteur et capteur
ServoMoteur monServoMoteurG(brocheServoG);
ServoMoteur monServoMoteurD(brocheServoD);
CapteurTouch monCapteurDepression(brocheCapteur);

//initialisation
void setup()
{
// Exception pour la connexion au wifi
  try
  {
    server.setup();
  }
  catch (const char *msg)
  {
    std::cerr << "Exception attrapée : " << msg << '\n';
    Serial.println("Exception attrapée : ");
    Serial.println(msg);
  }
  Serial.begin(9600);

// Initialisation des servos
  monServoMoteurG.AllumerActionneur(true);
  monServoMoteurD.AllumerActionneur(true);

// Initialisation des LEDs
  leds.push_back(LED(D8)); // LED rouge
  leds.push_back(LED(D3)); // LED jaune
  leds.push_back(LED(D4)); // LED verte
  for (LED &led : leds)
  {
    led.activer();
    delay(1000);
    led.desactiver();
  }

//Initialisation des croquettes 
  std::list<Croquette> maListeDecroquette;
  Croquette croquetteG;
  Croquette croquetteD;
  maListeDecroquette.push_back(croquetteG);
  maListeDecroquette.push_back(croquetteD);

//Obtenir l'adresse IP pour le serveur
  Serial.println("Début Programme");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

//Boucle principale
void loop()
{
// Boucle pour les requêtes du serveur
  server.loop();

//Condition pour qu'il reste de la nourriture
  if (monCapteurDepression.estEnfonce())
  {
    // Désactiver le buzzer et les LEDs
    monBuzzer.desactiver();
    for (LED &led : leds)
    {
      led.desactiver();
    }

    Serial.println("Capteur appuye");

// Si le choix est 0, on ne fait rien
    if (server.choix == 0)
    {
      Serial.println("choix 0");
      monServoMoteurD.tourner(0);
      monServoMoteurG.tourner(0);
    }
// Si le choix est 1 (depuis serveur), on tourne le servo de droite
    else if (server.choix == 1)
    {
      // Activer la led rouge et le servo de droite pendant 5 secondes 
      Serial.println("choix 1");
      leds[1].activer();
      monServoMoteurD.tourner(180);
      delay(5000);
      server.choix = 0;
    }
// Si le choix est 2 (depuis serveur), on tourne le servo de gauche
    else if (server.choix == 2)
    {
      // Activer la led verte et le servo de gauche pendant 5 secondes
      Serial.println("choix 2");
      leds[2].activer();
      monServoMoteurG.tourner(180);
      delay(5000);
      server.choix = 0;
    }
  }
  // Si le capteur n'est pas enfoncé et que le choix est 1 ou 2 sont sélectionné
  else if ((!monCapteurDepression.estEnfonce() && server.choix == 1) || (!monCapteurDepression.estEnfonce() && server.choix == 2))
  {
    // Activer la led rouge et le buzzer 
    server.choix = 0;
    monBuzzer.activer();
    leds[0].activer();
  }
  else
  {
    // Remettre le buzzer et les servomoteurs à l'état initial
    server.choix = 0;
  }

  // Comparer les deux LEDs avec l'opérateur ==
  if (leds[0] == leds[1])
  {
    Serial.println("Les deux LEDs sont identiques.");
  }
  else
  {
    Serial.println("Les deux LEDs sont differentes.");
  }
}
