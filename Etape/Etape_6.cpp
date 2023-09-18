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

        friend ostream& operator<<(ostream& os, const Point2D& other){
            os << "Coordonnees : x: " << other.x << "  y: " << other.y;
            return os;
        }

        friend istream& operator>>(istream& is, Point2D& other){
            cout << "Entrez le coordonnee x : ";
            is >> other.x;
            cout << "Entrez le coordonnee y : ";
            is >> other.y;
            return is;
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

    Point2D p1(1, 2);
    cout << p1 << endl;

    Point2D p2;
    cin >> p2; // si vous saisissez 1 (puis return) 2 (puis return)
    cout << p2 ; // vous devriez voir s’afficher les coordonnées 1 et 2

    return 0;
}