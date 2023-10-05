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

        //Destructeur appelé par le compilateur
        ~vecteur()
        {
            delete [] p; // libérer la mémoire
            //cout << "Destructeur vecteur avec : " << p << endl;
        }

        vecteur(int dimension, float val){
            dim=dimension;
            p = new float [dim];
            for (int i = 0; i < dim; i++)
            {
                p[i]=val;
            }
        }

        // opérateur d'indiçage
        float & operator [] (int indice) const{   // const : opérateur ne modifie pas l'objet
            return p[indice];
        } 

        //opérateur d'affection permet de copier le tableau sans les @
        //passage en référence = modifie directement la ref
        vecteur operator = (const vecteur& temp){ 
            vecteur returnVect;
            dim = temp.dim;
            p = new float [dim];

            for(int i=0; i<dim; i++){
                p[i] = temp.p[i];
            }
            return returnVect;
        } 

        //Surcharge du +
        vecteur operator + (const vecteur& other){
            if (dim != other.dim)
                throw "Erreur : Les deux vecteurs ne sont pas de la meme taille"; // throw permet d'exit
            vecteur returnVect(dim, 0);
            for(int i=0; i<dim; i++){
                returnVect.p[i] = p[i] + other.p[i];
            }
            return returnVect;
        }

        vecteur& operator += (const vecteur& other){
            if (dim != other.dim)
                throw "Erreur : Les deux vecteurs ne sont pas de la meme taille"; // throw permet d'exit
            for(int i=0; i<dim; i++){
                p[i] += other.p[i];
            }
            return (*this);
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

// Indiçage
// vecteur v1(3) ;
// float f ;
// v1[0] = 3.1 ; // action 1 : ici on modifie la valeur d’un élément stocké dans le vecteur
// f= v1[0] ; // action 2 : ici on récupère la valeur d’un élément du vecteur
// v1.affiche();


// Affection
// vecteur v1(2, 1), v2(2, 2), v3(2,3);
// cout<< "Adresse v2 : "<< &v2[0] <<endl; // Vérifier qu'avec l'opérateur =, l'@ n'est pas copié
// v2 = v1;
// cout<< "Adresse v1 : "<< &v1[0] <<endl;
// cout<< "Adresse v2 : "<< &v2[0] <<endl;
// v1.affiche();
// v2.affiche();


// Addition
//  vecteur v1(3,0), v2(2,2), v3(3,3);
// try{
// v1=v2+v3 ;
// v1.affiche();
// v2.affiche();
// v3.affiche();
// }
// catch(const char * excep)
// {
//     cout << excep << endl;
// }

//Addition Egale
vecteur v1(3,1), v2(3,2);
try{
v1.affiche();
v1+=v2;
v1.affiche();
}
catch(const char * excep)
{
    cout << excep << endl;
}

return 0;
}
