#include <Servo.h>

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
    ServoMoteur(int brocheServo) {
        monServo.attach(brocheServo);
    }

    void tourner(int angle) {
        monServo.write(angle);
    }
};

// Pin pour le servo
const int brocheServo = 14;
ServoMoteur monServoMoteur(brocheServo);
int angle = 0; // Angle initial du servo

void setup() {
    // Initialisation du port série
    Serial.begin(9600);
}

void loop() {
    // Variation de l'angle du servo
    monServoMoteur.tourner(angle);

    // Incrémentation de l'angle pour la prochaine itération
    angle += 10;
    if (angle > 180) {
        angle = 0; // Réinitialisation de l'angle à 0 une fois qu'il dépasse 180 degrés
    }

    delay(1000); // Attendre une seconde avant de changer l'angle du servo
}