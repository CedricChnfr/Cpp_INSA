#include <Servo.h>
#include <iostream>
#include <list> // pour list
#include <arduino.h>
class Actionneur {
private:
    bool ON;

public:
    Actionneur() : ON(false) {} // Initialise ON à false par défaut

    void AllumerActionneur(bool Allumer) {
        ON = Allumer;
    }

    bool GetETAT() {
        return ON;
    }
};


class ServoMoteur : public Actionneur {
private:
    Servo monServo;

public:
    ServoMoteur(int brocheServo) : Actionneur() {
        monServo.attach(brocheServo);
    }

    void tourner(int angle) {
        if (GetETAT()) {
            monServo.write(angle);
        }
    }
};

class Croquette  {
private:
     String NomCroquette;
     int positionDansGamelle;

public:
   String GetNom(){
    return NomCroquette;
   }
   void SetNom(String str){
     NomCroquette=str;
   }
    void setPosition(int position){
    positionDansGamelle=position;
   }
   int  getPosition(){
     return positionDansGamelle;
   }
};

class CapteurTouch {
private:
    int brocheCapteurTactile;

public:
    CapteurTouch(int broche) : brocheCapteurTactile(broche) {
        pinMode(brocheCapteurTactile, INPUT);
    }

    bool estEnfonce() {
        int etatCapteur = digitalRead(brocheCapteurTactile);
        return (etatCapteur == HIGH);
    }
};


// Pin pour le servo
const int brocheServoG = 14;
const int brocheServoD = 12;
const int brocheCapteur = 13;

void setup() {
    // Initialisation du port série
    Serial.begin(9600);
    
}

void loop() {
    //si le capteur est enfoncer ou non 
    CapteurTouch monCapteurDepression(brocheCapteur);
    //choix 
    int choix=1; 
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
    int angle = 0; // Angle initial du servo

    while(1){
   

    
      if (choix==1) {
        while(monCapteurDepression.estEnfonce()){
          monServoMoteurG.tourner(180);
        }
        monServoMoteurG.tourner(0);
      }
      if (choix==2) {
        while(monCapteurDepression.estEnfonce()){
          monServoMoteurD.tourner(180);
        }
        monServoMoteurD.tourner(0);
      }

    }
    
}