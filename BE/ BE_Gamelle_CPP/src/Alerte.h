#include <iostream>
#include <Arduino.h>


class Alerte {
protected:
    int pin;
    bool etat;

public:
    Alerte(int pin) : pin(pin), etat(false) {}

    virtual void activer() = 0; // Méthode purement virtuelle
    virtual void desactiver() = 0; // Méthode purement virtuelle
};

class Buzzer : public Alerte {
public:
    Buzzer(int pin) : Alerte(pin) {
        pinMode(pin, OUTPUT);
    }

    ~Buzzer() {digitalWrite(pin, LOW);}// Destructeur

    void activer() override {
        etat = true;
        digitalWrite(pin, HIGH);
        delay(100); // Attendre 100 millisecondes
        digitalWrite(pin, LOW);
        etat = false;
    }

    void desactiver() override {
        etat = false;
        digitalWrite(pin, LOW);
    }
};

class LED : public Alerte {
public:
    LED(int pin) : Alerte(pin) {
        pinMode(pin, OUTPUT);
    }

    ~LED() {digitalWrite(pin, LOW);}// Destructeur

    void activer() override {
        etat = true;
        digitalWrite(pin, HIGH);
    }

    void desactiver() override {
        etat = false;
        digitalWrite(pin, LOW);
    }

bool operator == (const LED& led) const {
        return pin == led.pin;
    }

};