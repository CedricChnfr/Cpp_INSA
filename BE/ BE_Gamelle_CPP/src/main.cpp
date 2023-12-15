#include "Wifi_Serveur.h"
#include "Servomotor.h"
#include <iostream>

// WiFiLEDServer server("Redmi Note 10 Pro", "totototo", 15);
// WiFiLEDServer server("Les Restos De La Coo", "KB6zDjij");
// WiFiLEDServer server("simple", "mama1234");
// WiFiLEDServer server("Zyxel_BA41", "Lord&Lady");
WiFiLEDServer server("Livebox-8C50", "Chanfreaulafamille5");
// Pin pour le servo
const int brocheServoG = 12; // D6
const int brocheServoD = 5;  // D1
const int brocheCapteur = 13;
int previouschoix = 0;

ServoMoteur monServoMoteurG(brocheServoG);
ServoMoteur monServoMoteurD(brocheServoD);
CapteurTouch monCapteurDepression(brocheCapteur);

void setup()
{
  server.setup();
  Serial.begin(9600);

  monServoMoteurG.AllumerActionneur(true);
  monServoMoteurD.AllumerActionneur(true);

  std::list<Croquette> maListeDecroquette;
  Croquette croquetteG;
  Croquette croquetteD;
  maListeDecroquette.push_back(croquetteG);
  maListeDecroquette.push_back(croquetteD);

  Serial.println("Début Programme");
}

void loop()
{
  server.loop();

  // Serial.print("Adresse IP : ");
  // Serial.println(WiFi.localIP());

  // Serial.println("choix: " + String(server.choix));

  if (monCapteurDepression.estEnfonce())
  {
    Serial.println("Capteur appuye");

    if (server.choix == 0)
    {
      Serial.println("choix 0");
      monServoMoteurD.tourner(0);
      monServoMoteurG.tourner(0);
    }
    else if (server.choix == 1)
    {
      Serial.println("choix 1");
      monServoMoteurD.tourner(180);
      delay(1000);
      server.choix = 0;
    }
    else if (server.choix == 2)
    {
      Serial.println("choix 2");
      monServoMoteurG.tourner(180);
      delay(1000);
      server.choix = 0;
    }
  }
  else
  {
    server.choix = 0; // Reset the choice if the sensor is not pressed
  }
}
