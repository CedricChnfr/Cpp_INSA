//g++ -o Etape_1 Etape_1.cpp | .\Etape_1

#include <iostream>
#include <cstdlib>
using namespace std;


//Passage par référence
void maj1(int &x) {
    x *= 2;
}

//Passage par pointeur
void maj2(int * x) {
    (*x) *= 4;
}

int main()
{
    int i =2 ; 
    maj1(i) ; 
    cout << i <<endl ;  // doit afficher 4 à l’écran 
    
    i=2;
    maj2(&i) ; 
    cout << i <<endl ;  // doit afficher 8 à l’écran 
}