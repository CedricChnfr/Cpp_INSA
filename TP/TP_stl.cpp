//g++ -o TP_stl TP_stl.cpp | .\TP_stl
#include <iostream>
#include <cstdlib>
#include <list>
#include <typeinfo>
#include <vector> // pour vector
#include <list> // pour list
#include <set> // pour set
#include <map> // pour dictionary
#include <algorithm> // pour sort
using namespace std;

//////////////////////PARTIE1//////////////////////


//VECTOR////////////////////////
// int main() {
//     vector<float> v1(10);
//     vector<float> v2;

//     // Remplir v1 avec des valeurs régulièrement réparties entre 0.0 et 1.0
//     for(int i = 0; i < 10; i++) {
//         v1[i] = i / 10.0;
//     }

//     // Copier v1 dans v2
//     v2 = v1;

//     // Effacer la deuxième moitié de v2
//     v2.erase(v2.begin() + 5, v2.end());

//     // Afficher v2
//     for(auto val : v2) {
//         cout << val << " ";
//     }

//     return 0;
// }

//LIST////////////////////////
// int main() {
//     char i;
//     list<int> l1, l2;
//     list<int>::iterator it;

//     for(i='A';i<='J';i++){
//         l1.push_back(i);
//     }
//     for(it=l1.begin(); it!=l1.end(); it++)cout<<static_cast<char>(*it)<<" ";
//     cout<<endl;

//     l2=l1;
//     l2.erase(l2.begin(), next(l2.begin(), 5));
    
//     // Afficher l2
//     for(it=l2.begin(); it!=l2.end(); it++)cout<<static_cast<char>(*it)<<" ";

//     return 0;
// }


//SET////////////////////////
// int main() {
//     set<string> students;

//     // Ajouter des noms d'élèves à l'ensemble
//     students.insert("Alice");
//     students.insert("Bob");
//     students.insert("Charlie");
//     students.insert("David");

//     // Afficher les éléments de l'ensemble
//     for(const auto& student : students) {
//         cout << student << " ";
//     }
//     cout << endl;

//     // Supprimer les 2 premiers noms
//     students.erase(students.begin());
//     students.erase(students.begin());

//     // Afficher de nouveau l'ensemble
//     for(set<string>::iterator it = students.begin(); it != students.end(); ++it) 
//     {
//     cout << *it << " ";
//     }

//     return 0;
// }


//DICTIONNAIRE////////////////////////
// int main(){
//     map<string, int> dico;

//     dico["Cedric"] = 679791782;
//     dico ["Alice"] = 579791783;
//     dico ["Bob"] = 679791784;
//     dico ["Charlie"] = 579791785;
//     dico ["David"] = 679791786;


//     for(auto val : dico) {
//         cout << val.first << " " << val.second << endl;
//     }
//     cout<<endl;

//     // Supprimer tous les numéros commençant par 5
//     for(auto it = dico.begin(); it != dico.end(); ) {
//         if(it->second / 100000000 == 5) {
//             it = dico.erase(it);
//         } else {
//             ++it;
//         }
//     }

//     // Afficher de nouveau le dictionnaire
//     for(map<string, int>::iterator it = dico.begin(); it != dico.end(); ++it) {
//     cout << it->first << ": " << it->second << std::endl;
//     }

// }



// TRIER UN VECTOR////////////////////////
// int main() {
//     vector<string> v1(5);

//     v1.push_back("Cedric");
//     v1.push_back("Thomas");
//     v1.push_back("Charlie");
//     v1.push_back("Alban");
//     v1.push_back("Yves");

//     for(auto val : v1) {
//         cout << val << " "<<endl;
//     }
//     cout<<endl;
    
//     //Ordre alphabétique
//     sort(v1.begin(), v1.end());

//     for(auto val : v1) {    
//         cout << val << " "<<endl;
//     }
//     return 0;
// }


// int main(){
//     list<string> phrase;

//     phrase.push_back("il");
//     phrase.push_back("fait");
//     phrase.push_back("beau");

//    // Trouver la position du mot "beau"
// auto it = find(phrase.begin(), phrase.end(), "beau");

//     if(it != phrase.end()) {
//         phrase.insert(it, "tres"); //Insérer très avant beau
//         cout << "Le mot \"beau\" se trouve a la position " << distance(phrase.begin(), it) << endl;
//     } else {
//         cout << "Le mot \"beau\" n'a pas ete trouve" << endl;
//     }

//     for(list<string>::iterator it = phrase.begin(); it != phrase.end(); ++it){
//         cout << *it << " ";
//     }

//     return 0;
// } 



//////////////////////PARTIE2//////////////////////

 class Vecteur {
    map<int, double> data;

    public:
    Vecteur() {}

    double &operator[](int i){
        return data[i];
    }

    double operator()(int index) const {
        auto it = data.find(index);
        return it == data.end() ? 0.0 : it->second;
    }

    friend ostream& operator<<(ostream& os, const Vecteur& vec) {
        for(const auto& pair : vec.data) {
            os << pair.first << ": " << pair.second << " ";
        }
        return os;
    }

    double operator*(const Vecteur& vec) const {
        double result = 0.0;
        for(const auto& pair : data) {
            result += pair.second * vec(pair.first);
        }
        return result;
        }

    double operator - (const Vecteur& vec) const {
        double result = 0.0;
        for(const auto& pair : data) {
            result += pair.second - vec(pair.first);
        }
        return result;
    }

    double operator + (const Vecteur& vec) const {
        double result = 0.0;
        for(const auto& pair : data) {
            result += pair.second + vec(pair.first);
        }
        return result;
    };

    };

class Matrice {
    std::map<int, Vecteur> data;

public:
    Matrice() {}

    Vecteur& operator[](int index) {
        return data[index];
    }

    double operator()(int i, int j) const {
        auto it = data.find(i);
        return it == data.end() ? 0.0 : it->second(j);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrice& mat) {
        for(const auto& pair : mat.data) {
            os << pair.first << ": " << pair.second << "\n";
        }
        return os;
    }

    // Define other operators as needed
};



int main() {
    // Créer un vecteur creux
    Vecteur v;
    v[3] = 4.5;
    v[10] = 3.2;

    // Afficher le vecteur
    std::cout << "Vecteur v: " << v << std::endl;

    // Créer une autre vecteur pour tester les opérations
    Vecteur w;
    w[3] = 1.5;
    w[5] = 2.7;

    std::cout << "Vecteur w: " << w << std::endl;


    // Tester les opérations
    std::cout << "v * w: " << v * w << std::endl;
    std::cout << "v - w: " << v - w << std::endl;
    std::cout << "v + w: " << v + w << std::endl;

    // Créer une matrice creuse
    Matrice m;
    m[2] = v;
    m[5] = w;

    // Afficher la matrice
    std::cout << "Matrice m: " << m << std::endl;

    // Accéder à un élément de la matrice
    std::cout << "m(2, 3): " << m(2, 3) << std::endl;

    return 0;
}