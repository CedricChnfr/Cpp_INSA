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
        friend vecteur<Y> operator * (const vecteur<Y>& v1, const vecteur<Y>& v2);

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

//Contient des vecteurs
template <typename T>
class matrice{
    protected:
        vecteur<T>* tab[10];
        int dim;

    public:
    matrice(int dimension) : dim(dimension) {
        for (int i = 0; i < dim; i++) {
            tab[i] = nullptr;
        }
    }

    ~matrice(){
        for (int i = 0; i < dim; i++)
        {
            delete tab[i];
        }
    }

    void addvecteur(int index, vecteur<T>* v) {
        if (index >= 0 && index < dim) {
            if (tab[index] == nullptr) {
                tab[index] = new vecteur<T>(*v);
            } else {
                tab[index] = v;
            }
        }
    }

    vecteur<T>* getvecteur(int index) {
        if (index >= 0 && index < dim) {
            return tab[index];
        }
        return nullptr;
    }
          
};

//Surcharge du *
template <typename Y>
vecteur<Y> operator * (const vecteur<Y>& v1, const vecteur<Y>& v2){
    if (v1.dim != v2.dim)
        throw "Erreur : Vecteur de taille différente"; // throw permet d'exit
    vecteur<Y> returnVect(v1.dim, 0);
    for(int i=0; i<v1.dim; i++){
        returnVect.p[i] = v1.p[i] * v2.p[i];
    }
    return returnVect;
    }



int main(){
    vecteur_intel<float> v1, v2;
    matrice<float> poly(10);
    cin >> v1;
    cout << v1 << endl;
    cin >> v2;
    cout << v2 << endl;

    try{
        cout << v1 * v2 << endl;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }

    poly.addvecteur(0, &v1);
    poly.addvecteur(1, &v2);

    cout << poly.getvecteur(0) << endl;
    cout << poly.getvecteur(1) << endl;

   
}
