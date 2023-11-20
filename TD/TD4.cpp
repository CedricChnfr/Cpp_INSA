#include <iostream>
#include <cstdlib>
#include <fstream> //manipuler un fichier
using namespace std;

//template pour recevoir n'importe quel type
template <typename T>

class vecteur{
    protected: //Pour que les variables soit accessible dans la classe fille 
        int dim;
        T * p;

    public:
        int get_dimension() const {
        return dim;
        }

        vecteur() : dim(0), p(nullptr) {}

        //Constructeurs 
        vecteur(int dimension) : dim(dimension){
            p = new T[dim];
            for (int i = 0; i < dim; i++)
            {
                p[i]=0;
            }
        }

        //Destructeur appelé par le compilateur
        ~vecteur()
        {
            delete [] p; // libérer la mémoire
            //cout << "Destructeur vecteur avec : " << p << endl;
        }

        vecteur(int dimension, float val) : dim(dimension){
            p = new T [dim];
            for (int i = 0; i < dim; i++)
            {
                p[i]=val;
            }
        }

        // opérateur d'indiçage
        T & operator [] (int indice){   // const : opérateur ne modifie pas l'objet
            return p[indice];
        } 

        //opérateur d'affection permet de copier le tableau sans les @
        //passage en référence = modifie directement la ref
        vecteur& operator = (const vecteur& temp){ 
            vecteur returnVect;
            dim = temp.dim;
            p = new T [dim];

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


        template <typename Y>
        friend ostream& operator<<(ostream& os, const vecteur<Y>& v) {
            os << "Vecteur de dimension "<< v.dim << " [";
            for (int i = 0; i < v.dim; ++i) {
                os << v.p[i];
                if (i != v.dim - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

        template <typename Y>
        friend istream & operator >> (istream &is, vecteur<Y> & v){
            cout << "Entrez la dimension du vecteur : ";
            is >> v.dim;
            v.p = new Y [v.dim];
            for (int i = 0; i < v.dim; i++)
            {
                cout << "Entrez la valeur de la valeur " << i << ": ";
                is >> v.p[i];
            }
            return is;
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


template <typename T>
class vecteur_intel : public vecteur<T>{
    public:
    vecteur_intel() : vecteur<T>() { 
        // pas de code
    }

    vecteur_intel(int dimension) : vecteur<T>(dimension) { 
        // pas de code
    }

    vecteur_intel(int dimension, float size) : vecteur<T>(dimension, size) { 
        // pas de code
    }

    // Vecteur de recopie intelligente
    vecteur_intel(const vecteur_intel &v) : vecteur<T>(v) { 
        // pas de code
    }
    // Si pas de modifs, les méthodes ne sont pas appelées
    // Les opérateurs sont directement hérité dans la classe fille

    //Surcharge du +
    vecteur_intel operator + (const vecteur_intel& other){
        int maxSize = (this->dim > other.dim) ? this->dim : other.dim;
        vecteur_intel returnVect(maxSize);
        for (int i = 0; i < maxSize; i++) {
            T value1 = (i < this->dim) ? this->p[i] : T();
            T value2 = (i < other.dim) ? other.p[i] : T();
            returnVect.p[i] = value1 + value2;
        }
        return returnVect;
    }
};


int main(){
    // vecteur_intel<float> v(5, 3);

    // for (int i = 0; i < 5; i++) {
    //     v[i] = i * 2.5;
    // }

    // cout << "Contenu du vecteur : ";
    // for (int i = 0; i < 5; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // return 0;

    vecteur_intel<float> v;
    cin >> v;
    cout << v << endl;
}
