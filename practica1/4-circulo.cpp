/*******************************************************************************
 * Curso de Programación 1. Tema 1
 * Autores: Miguel Ángel Latre
 * Última revisión: 14 de septiembre de 2021
 * Resumen: Programa que solicita al usuario la longitud de un radio y escribe 
 *          en la pantalla el área del círculo correspondiente.
 ******************************************************************************/
#include <iostream>
using namespace std;

const double PI = 3.14159265358979323846;

/*
 * Programa que solicita al usuario la longitud de un radio y escribe en la
 * pantalla el área del círculo corresondiente.
 */
int main() {
    cout << "Escriba el radio de un círculo: ";
    
    double r;
    cin >> r;
    
    cout << "El área de un círculo de radio " << r << " es " 
         << PI * r * r << endl;
    
    return 0;
}
