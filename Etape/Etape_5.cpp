#include <iostream>
#include <cstdlib>
using namespace std;
#include <iostream>
#include <cstdlib>
using namespace std;

class Point2D{
    protected:
        int x=0, y=0;

    public:
        Point2D() {}
        Point2D(int initialX, int initialY) {x=initialX;y=initialY;}     // Constructeur lors de la déclaration du point 

        //Destructeur appelé par le compilateur
        ~Point2D()
        {
            //cout << "Destructeur point2d avec : " << x << endl;
        }

        //Surcharge du +
        Point2D& operator+(const Point2D& other){
            this->x = this->x + other.x;
            this->y = this->y + other.y;
            return (*this);
        }

        Point2D operator*(int other){
            this->x = this->x * other;
            this->y = this->y * other;
            return (*this);
        }

        void saisie(int enter_x, int enter_y){
            x = enter_x;
            y = enter_y;
        }

        //Virtual : l’appel de la fonction est lié à sa définition lors de l’exécution
        virtual void affiche(){
            cout <<" Coordonnee : x : " <<x <<"  y: "<<y << endl;
        }

        void affiche2(){
            affiche();
        }
};

class Point3D : public Point2D{
    private:
        int z=0;
    public:
    Point3D() : Point2D() {}
    Point3D(int initialX, int initialY, int initialZ) : Point2D(initialX, initialY) {z=initialZ;}     // Constructeur lors de la déclaration du point 

    void saisie(int enter_x, int enter_y, int enter_z){
        Point2D::saisie(enter_x, enter_y);
        z = enter_z;
    }

    virtual void affiche(){
        Point2D::affiche();
        cout << "  z: " << z << endl;
    }

    Point3D& operator+(const Point3D& other){
        this->x = this->x + other.x;
        this->y = this->y + other.y;
        this->z = this->z + other.z;
        return(*this);
    }

    Point3D& operator*(int other){
        this->x = this->x * other;
        this->y = this->y * other;
        this->z = this->z * other;
        return(*this);
    }
};

int main(){

    Point2D point1;
    Point2D point2(3,4);
    Point2D point3;

    point1.saisie(1,2);
    point1.affiche();
    point2.affiche2(); 

    Point3D point4;
    Point3D point5(4,5,6);
    Point3D point6;

    point4.saisie(1,2,3);
    point4.affiche();
    point5.affiche2(); 


    return 0;
}