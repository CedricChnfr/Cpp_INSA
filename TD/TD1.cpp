#include <iostream>
#include <cstdlib>
using namespace std;

class vecteur{
    private:
        int dim;
        float * p;
    public:
        vecteur() : dim(0), p(nullptr) {}

        //Constructeurs 
        vecteur(int dimension) : dim(dimension){
            p = new float [dim];
            for (int i = 0; i < dim; i++)
            {
                p[i]=0.0f;
            }
        }

        vecteur(int dimension, float val){
            dim=dimension;
            p = new float [dim];
            for (int i = 0; i < dim; i++)
            {
                p[i]=val;
            }
        }

        //Méthode
        void saisie() {
            for (int i = 0; i < dim; i++) {
                cout << "Entrer la valeur de la valeur " << i << ": ";
                cin >> p[i];
            }
        }

        void affiche(){
            cout<<"Vecteur de dimension "<< dim << " : [";
            for (int i = 0; i < dim; i++)
            {
                cout<<" "<<p[i]<<" ";
            }
            cout<<"]"<<endl;
        }
        
               
};

int main(){

    vecteur v1(3);
    v1.saisie();
    v1.affiche();

    vecteur v0 ; // vecteur vide
    vecteur v2(10) ; // vecteur de 10 élements
    vecteur v3(10,1.2) ; // vecteur de 10 éléments initialiés à 1.2
    vecteur v4(v3) ; // constructeur de recopie qui crée v4 une copie de v3

    v0.affiche();
    v2.affiche();
    v3.affiche();
    v4.affiche();
    return 0;
}