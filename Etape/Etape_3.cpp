#include <iostream>
#include <cstdlib>
using namespace std;

class Point2D{
    private:
        int x=0, y=0;

    public:
        Point2D() {x=0;y=0;}    // Constructeur par défaut dans le cas où cordonnées non entrée (point1 dans main)
        //Point2D() {}  Méthode 2
        Point2D(int initialX, int initialY) {x=initialX;y=initialY;}     // Constructeur lors de la déclaration du point 
        
        //Destructeur appelé par le compilateur
        ~Point2D()
        {
            //cout << "Destructeur point2d avec : " << x << endl;
        }

        //Surcharge du +
        Point2D operator+(const Point2D& other) const {
        return Point2D(x + other.x, y + other.y);
        }

        Point2D operator*(int other) const {
        return Point2D(x * other, y * other);
        }

        void saisie(int enter_x, int enter_y){
            x = enter_x;
            y = enter_y;
        }

        void affiche(){
            cout <<"Coordonnee : x: " <<x <<" et y: "<<y<<endl;
        }
};

int main(){

    Point2D A(1, 2), B(3, 4), C;
    C = A + B; 
    C.affiche();  

    C = A*5;
    C.affiche();

    return 0;
}