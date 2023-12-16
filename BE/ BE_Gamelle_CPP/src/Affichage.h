#include <iostream>
#include "Arduino.h"

class MonContenu {
public:
  std::string texte;

  MonContenu(const std::string& texte) : texte(texte) {}

  friend std::ostream& operator<<(std::ostream& os, const MonContenu& contenu) {
    return os << contenu.texte;
  }
};