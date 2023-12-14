#include "Wifi_Serveur.h"
#include "Servomotor.h"
#include <iostream>

//WiFiLEDServer server("Redmi Note 10 Pro", "totototo", 15);
//WiFiLEDServer server("Les Restos De La Coo", "KB6zDjij", 15);
WiFiLEDServer server("simple", "mama1234", 15);
// Pin pour le servo
const int brocheServoG = 14;
const int brocheServoD = 12;
const int brocheCapteur = 13;
int previouschoix=0;



void setup() {
  server.setup();
  Serial.begin(9600);
  server.choix = 0;
}

void loop() {
  server.loop();
  // Serial.print("IP address: ");
  // Serial.println(WiFi.localIP());  // Print the IP address
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


if (server.choix != previouschoix){
  std::cout << "Rentre car Previous = Actualchoix " << std::endl;
  if (server.choix == 0) {
    printf("choix = 0");
    //server.choix = 0;
    monServoMoteurG.tourner(0);
    monServoMoteurD.tourner(0);
  } else if (server.choix == 1 /*&& monCapteurDepression.estEnfonce()*/) {
    printf("choix = 1\n");
    monServoMoteurG.tourner(180);
    delay(5000);
    //server.choix = 0;

    monServoMoteurD.AllumerActionneur(false);
  } else if (server.choix == 2 /*&& monCapteurDepression.estEnfonce()*/) {
    printf("choix = 2\n");
    monServoMoteurD.tourner(180);
    delay(5000);
    //server.choix = 0;
  }
  previouschoix = server.choix;
}

}    