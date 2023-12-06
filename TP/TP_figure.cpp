//g++ -o TP_figure TP_figure.cpp | .\TP_figure
#include <iostream>
#include <cstdlib>
#include <list>
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
    std::list<Figure*> figures2;
    std::list<Figure> MaListeDeForme;
    //std::list<Figure>::iterator it = MaListeDeForme.begin();

    // Initialize the array
    figures[0] = new Carre(5);
    figures[1] = new Cercle(3, "red");
    figures[2] = new TriangleEquilateral(4);

    figures2.push_back(new Carre(5));
    figures2.push_back(new Cercle(3, "red"));
    figures2.push_back(new TriangleEquilateral(4));

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

    for (Figure* figure : figures) {
    cout << "Perimeter: " << figure->perimetre() << endl;
    figure->afficherCaracteristiques();
    cout << endl;
    }

    Carre Carre1(5);
    MaListeDeForme.push_back( Carre1); // Ajout de figures à la liste
    //MaListeDeForme.push_back( Cercle(3, "red"));
    //MaListeDeForme.push_back(TriangleEquilateral(4));

    //MaListeDeForme.pop_back(); // Supprimer le dernier élément de la liste

    // Utilisation d'un itérateur pour parcourir la liste
    

    // std::cout << "Contenu de la liste : ";
    // while (it != MaListeDeForme.end()) {
    //     std::cout << it->perimetre() << " ";
    //      it->afficherCaracteristiques() ;
    //     ++it; // Ne pas oublier d'incrémenter l'itérateur pour éviter une boucle infinie
    // }

   

    return 0;
}