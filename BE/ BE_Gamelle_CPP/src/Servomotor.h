#include <Servo.h>
#include <iostream>
#include <list> // pour list

// Classe pour gérer les actionneurs
class Actionneur {
private:
    bool ON;

public:
    // Initialise ON à false par défaut
    Actionneur() : ON(false) {} 

    ~Actionneur() {} // Destructor

    //Méthode pour allumer ou éteindre l'actionneur
    void AllumerActionneur(bool Allumer) {
        ON = Allumer;
    }

    //Méthode pour récupérer l'état de l'actionneur
    bool GetETAT() {
        return ON;
    }
};

// Classe pour gérer les servomoteurs
class ServoMoteur : public Actionneur {
private:
    Servo monServo;

public:
    // Constructeur pour initialiser le servo avec la broche
    ServoMoteur(int brocheServo) : Actionneur() {
        monServo.attach(brocheServo);
    }

    // Destructeur pour détacher le servo
    ~ServoMoteur() {monServo.detach();}

    // Méthode pour initialiser le servo à la position 0
    void initialiser() {
        monServo.write(0);  // Positionner le servo à 0 degré lors de l'initialisation
    }

    // Méthode pour tourner le servo à un angle donné
    void tourner(int angle) {
        if (GetETAT()) {
            monServo.write(angle);
        } 
    }
};

//Class pour les croquettes
class Croquette  {
private:
     String NomCroquette;
     int positionDansGamelle;

public:
    // Obtenir le nom de la croquette
   String GetNom(){
    return NomCroquette;
   }
   // Définir le nom de la croquette
   void SetNom(String str){
     NomCroquette=str;
   }
    // Définir la position de la croquette dans la gamelle
    void setPosition(int position){
    positionDansGamelle=position;
   }
    // Obtenir la position de la croquette dans la gamelle
   int  getPosition(){
     return positionDansGamelle;
   }
    // Destructeur
    ~Croquette() {}
};

// Classe pour gérer les alertes
class CapteurTouch {
private:
    int brocheCapteurTactile;

public:
    // Constructeur pour initialiser le capteur tactile
    CapteurTouch(int broche) : brocheCapteurTactile(broche) {
        pinMode(brocheCapteurTactile, INPUT);
    }

    // Destructeur
    ~CapteurTouch() {}

    // Méthode pour vérifier si le capteur est enfoncé
    bool estEnfonce() {
        int etatCapteur = digitalRead(brocheCapteurTactile);
        return (etatCapteur == HIGH);
    }

    // Méthode pour vérifier si le capteur est relâché
    bool estRelache() {
        int etatCapteur = digitalRead(brocheCapteurTactile);
        return (etatCapteur == LOW);
    }

    // Méthode pour obtenir l'état du capteur
    int getEtat() {
        return digitalRead(brocheCapteurTactile);
    }

};