#include "Wifi_Serveur.h"
#include "Servomotor.h"

//WiFiLEDServer server("Redmi Note 10 Pro", "totototo", 15);
WiFiLEDServer server("Les Restos De La Coo", "KB6zDjij", 15);
//WiFiLEDServer server("Teste_bornes89_5g", "mama1234", 15);
// Pin pour le servo
const int brocheServoG = 14;
const int brocheServoD = 12;
const int brocheCapteur = 13;

void setup() {
  server.setup();
  Serial.begin(9600);
}

void loop() {
  server.loop();
  printf("choix = %d\n", server.choix);
  //si le capteur est enfoncer ou non 
  CapteurTouch monCapteurDepression(brocheCapteur);
  //choix 
  // Liste 
  std::list<Croquette> maListeDecroquette;
  Croquette croquetteG;
  Croquette croquetteD;
  maListeDecroquette.push_back(croquetteG);
  maListeDecroquette.push_back(croquetteD);
  // Variation de l'angle du servo
  ServoMoteur monServoMoteurG(brocheServoG);
  ServoMoteur monServoMoteurD(brocheServoD);
  monServoMoteurG.AllumerActionneur(true);
  monServoMoteurD.AllumerActionneur(true);

  while (monCapteurDepression.estEnfonce()) {
    if (server.choix == 1) {
      monServoMoteurG.tourner(180);
      delay(10000);
      monServoMoteurG.tourner(0);
      server.choix = 0;
    } else if (server.choix == 2) {
      monServoMoteurD.tourner(180);
      delay(10000);
      monServoMoteurG.tourner(0);
      server.choix = 0;
    }
  }
}