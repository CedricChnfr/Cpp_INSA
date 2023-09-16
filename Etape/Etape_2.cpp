#include <iostream>
#include <cstdlib>
using namespace std;

class Point2D{
    private:
        int x, y;
        //int x=0, y=0; Méthode 2

    public:
        Point2D() : x(0), y(0) {}    // Constructeur par défaut dans le cas où cordonnées non entrée (point1 dans main)
        //Point2D() {}  Méthode 2
        Point2D(int initialX, int initialY) : x(initialX), y(initialY) {}     // Constructeur lors de la déclaration du point 

        void saisie(int enter_x, int enter_y){
            x = enter_x;
            y = enter_y;
        }

        void affiche(){
            cout <<"Coordonnee : x: " <<x <<" et y: "<<y<<endl;
        }

};

int main(){

    Point2D point1;                 // Utilisation du constructeur par défaut
    Point2D point2(3, 4);           // Utilisation du constructeur avec des valeurs initiales

    point1.affiche();
    point2.affiche();
    point1.saisie(8,9);
    point1.affiche();

    return 0;
}