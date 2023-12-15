#include <Servo.h>
#include <iostream>
#include <list> // pour list

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

    void initialiser() {
        monServo.write(0);  // Positionner le servo à 0 degré lors de l'initialisation
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