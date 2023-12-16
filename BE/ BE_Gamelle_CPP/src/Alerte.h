#include <iostream>
#include <Arduino.h>

// Classe pour gérer les alertes
class Alerte {
protected:
    int pin;
    bool etat;

public:
    // Constructeur pour initialiser la pin et l'état à false par défaut
    Alerte(int pin) : pin(pin), etat(false) {}

    virtual void activer() = 0; // Méthode purement virtuelle
    virtual void desactiver() = 0; // Méthode purement virtuelle
};

// Classe pour gérer le buzzer
class Buzzer : public Alerte {
public:
    // Constructeur pour initialiser la pin
    Buzzer(int pin) : Alerte(pin) {
        pinMode(pin, OUTPUT);
    }

    // Destructeur pour éteindre le buzzer
    ~Buzzer() {digitalWrite(pin, LOW);}// Destructeur

    // Méthode pour activer le buzzer
    void activer() override {
        etat = true;
        digitalWrite(pin, HIGH);
        delay(100); // Attendre 100 millisecondes
        digitalWrite(pin, LOW);
        etat = false;
    }

    // Méthode pour désactiver le buzzer
    void desactiver() override {
        etat = false;
        digitalWrite(pin, LOW);
    }
};

// Classe pour gérer les LEDs
class LED : public Alerte {
public:
    // Constructeur pour initialiser la pin
    LED(int pin) : Alerte(pin) {
        pinMode(pin, OUTPUT);
    }

    // Destructeur pour éteindre la LED
    ~LED() {digitalWrite(pin, LOW);}// Destructeur

    // Méthode pour activer la LED
    void activer() override {
        etat = true;
        digitalWrite(pin, HIGH);
    }

    // Méthode pour désactiver la LED
    void desactiver() override {
        etat = false;
        digitalWrite(pin, LOW);
    }

    // Surcharge de l'opérateur == pour comparer deux LEDs
    bool operator == (const LED& led) const {
        return pin == led.pin;
    }

};