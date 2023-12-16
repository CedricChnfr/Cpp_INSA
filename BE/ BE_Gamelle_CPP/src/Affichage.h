#include <iostream>
#include "Arduino.h"

// Classe pour gérer le contenu de la page web
class MonContenu {
public:
  std::string texte;

  // Constructeur pour initialiser le texte
  MonContenu(const std::string& texte) : texte(texte) {}

  // Surcharge de l'opérateur << pour afficher le texte
  friend std::ostream& operator<<(std::ostream& os, const MonContenu& contenu) {
    return os << contenu.texte;
  }
};