//g++ -o TP_figure TP_figure.cpp | .\TP_figure
#include <iostream>
#include <cstdlib>
#include <list>
#include <typeinfo>
using namespace std;


class Figure {
public:
    static int compteur;

    Figure(){compteur++;}

    ~Figure(){compteur--;}

    virtual int perimetre() = 0;
    virtual void afficherCaracteristiques() = 0;

    static int getCompteur() { return compteur; }

};

int Figure::compteur = 0;

class Polygone : public Figure {
    public:
    int nbCotes;

    //Constructeur
    Polygone(int nb) : nbCotes(nb) {}

    void afficherCaracteristiques() override {
        cout << "Polygone de " << nbCotes << " cote " << endl;
    }
};


class Rectangle : public Polygone {
public:
    int longueur;
    int largeur;

    //Constructeur
    Rectangle(int l, int L) : Polygone(4), longueur(l), largeur(L) {}

    //Fonctions
    int getlongueur() { return longueur; }
    int getlargeur() { return largeur; }

    void setlongueur(int l) { longueur = l; }
    void setlargeur(int L) { largeur = L; }

    int perimetre() override {
        return 2 * (longueur + largeur);
    }

    void afficherCaracteristiques() override {
        cout << "Rectangle -> longueur: " << longueur << " | largeur: " << largeur << endl;
    }

};

class Carre : public Rectangle {
    public:
    Carre(int c) : Rectangle(c, c) {}
};


class TriangleEquilateral : public Polygone {
    public:
    int cote;

    //Constructeur
    TriangleEquilateral(int c) : Polygone(3), cote(c) {}

    //Fonctions
    int getcote() { return cote; }
    void setcote(int c) { cote = c; }

    int perimetre() override {
        return 3 * cote;
    }

    void afficherCaracteristiques() override {
        cout << "Triangle -> cote: " << cote << endl;
    }
    
};

class Coloriable {
protected:
    string couleur;

public:
    Coloriable(string coul) : couleur(coul) {}

    string getCouleur() {
        return couleur;
    }

    void setCouleur(string coul) {
        couleur = coul;
    }
};

class Cercle : public Figure, public Coloriable {
    public:
    int rayon;

    // Constructor
    Cercle(int r, string coul) : Figure(), Coloriable(coul), rayon(r) {}

    //Fonctions
    int getrayon() { return rayon; }
    void setrayon(int r) { rayon = r; }

    int perimetre() override {
        return 2 * 3.14 * rayon;
    }

    void afficherCaracteristiques() override {
        cout << "Cercle -> rayon: " << rayon << " | couleur: " << getCouleur() <<endl;
    }
};


int main(){
    Figure * figures[3];
    list<Figure*> figuresList;

    // Initialize the array
    figures[0] = new Carre(5);
    figures[1] = new Cercle(3, "red");
    figures[2] = new TriangleEquilateral(4);

    //PushBack pour ajouter un élément
    figuresList.push_back(new Carre(10));
    figuresList.push_back(new Cercle(6, "red"));
    figuresList.push_back(new TriangleEquilateral(8));
    figuresList.push_back(new Rectangle(8, 3));

    //EXO1
    cout << "EXO1" << endl;
    //Loop
    for(int i=0; i<3; i++){
        cout<<"Perimetre: "<<figures[i]->perimetre()<<endl;
        figures[i]->afficherCaracteristiques();
        cout<<endl;
    }

    // Afficher le compteur
    cout << "Compteur: "<< figures[0]->getCompteur() << endl;
    

    // Libérer la mémoire
    for(int i=0; i<3; i++){
        delete figures[i];
    }

    //EXO2
    cout << "EXO2" << endl;

    list<Figure*>::iterator it;

    // Get an iterator to the first element (où je suis dans la liste)
    it = figuresList.begin();

    // Remove the last element
    figuresList.pop_back();

    // Loop through the list
    while (it != figuresList.end()) {
        cout << "Perimetre: " << (*it)->perimetre() << endl;
        (*it)->afficherCaracteristiques();
        
        // Check if the figure is a Cercle
        if (typeid(**it) == typeid(Cercle)) {
            Cercle* c = dynamic_cast<Cercle*>(*it);
            cout << "Color: " << c->getCouleur() << endl;
        }
        cout << endl;
        it++;
    }

    // Remember to delete the dynamically allocated objects when you're done with them to avoid memory leaks.
    for (it = figuresList.begin(); it != figuresList.end(); ++it) {
        delete *it;
    }
    figuresList.clear();

    return 0;
}