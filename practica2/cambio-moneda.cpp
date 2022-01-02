/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 

/* 
Programa que solicita por teclado una cantidad no negativa de euros y separa los euros de los centimos y calcula las pesetas a
las que equivalen.
*/


using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {

    int euros;
    double eurosInicial;
    double pesetas;
    int centimos;


    
    cout << "Escriba una cantidad no negativa de dinero en euros: " << bold << underline;
    cin >> eurosInicial;

    

    if(eurosInicial >= 0) {
        euros = (int)eurosInicial; // Obtengo la parte entera para los euros.
        centimos = round((eurosInicial - euros) * 100); // Obtengo los centiemos redondeados. INT(x*100+0,5)
        cout << reset << "Son "<< euros << " euros y " <<  centimos << " centimos que equivalen a " << round(eurosInicial * 166.386) << " pesetas";
    } else {
        cout << reset << "Los datos introducidos son erroneos"<< endl;
        return 1;
    }
    return 0;
}
