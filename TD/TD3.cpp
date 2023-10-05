#include <iostream>
#include <cstdlib>
#include <fstream> //manipuler un fichier
using namespace std;

class vecteur{
    protected: //Pour que les variables soit accessible dans la classe fille 
        int dim;
        float * p;
    public:

        int get_dimension() const {
        return dim;
        }
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


class vecteur_intel : public vecteur{
    public:
    vecteur_intel() : vecteur() { 
        // pas de code
    }

    vecteur_intel(int dimension) : vecteur(dimension) { 
        // pas de code
    }

    vecteur_intel(int dimension, float size) : vecteur(dimension, size) { 
        // pas de code
    }

    // Vecteur de recopie intelligente
    vecteur_intel(const vecteur_intel &v) : vecteur(v) { 
        // pas de code
    }
// Si pas de modifs, les méthodes ne sont pas appelées
// Les opérateurs sont directement hérité dans la classe fille

    //Surcharge du +
    vecteur_intel operator + (const vecteur_intel& other){
        int maxSize = (dim > other.dim) ? dim : other.dim; // Taille maximale
        vecteur_intel returnVect(maxSize);
        for(int i = 0; i < maxSize; i++){
            float value1 = (i < dim) ? p[i] : 0.0f; // condition ? valeur_si_vrai : valeur_si_faux
            float value2 = (i < other.dim) ? other.p[i] : 0.0f;

            returnVect.p[i] = value1 + value2; // Effectue l'addition
        }
        return returnVect;
    }
};


class vecteur_manip : public vecteur{
public:

    void register_file(const vecteur_intel &v)
    {
        // Spécifiez le nom du fichier dans lequel vous souhaitez enregistrer les données
        string filename = "TD3_vecteur.txt";

        // Ouvrez un fichier en mode écriture
        ofstream fichier(filename);
        // Vérifiez si l'ouverture du fichier a réussi
        if (fichier.is_open()) {
            // Écrivez les données du vecteur dans le fichier
            for (int i = 0; i < v.get_dimension(); i++) {
                fichier << v[i] << endl;
            }

            // Fermez le fichier après avoir terminé d'écrire
            fichier.close();
            cout << "Les données ont été enregistrées dans le fichier " << filename << endl;
        } else {
            cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        }
    }
};





int main(){

// Héritage constructeur
// vecteur_intel v2(2);
// v2.affiche();

// vecteur_intel v1(2, 7.0);
// v1.affiche();

// vecteur_intel v3(3, 5.0);
// vecteur_intel v4(v3);
// v4.affiche();


// Héritage Opérateur
vecteur_manip manip;
vecteur_intel v1(15,8), v2(40,10), v3(1,0);
v3= v1+v2;
v3.affiche();
manip.register_file(v3);


return 0;
}
