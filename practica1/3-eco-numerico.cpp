/*******************************************************************************
 * Curso de Programación 1. Tema 1
 * Autores: Miguel Ángel Latre
 * Última revisión: 14 de septiembre de 2021
 * Resumen: Programa que solicita un número entero al usuario y lo escribe en 
 *          pantalla.
 ******************************************************************************/
#include <iostream>
using namespace std;

/*
 * Programa que solicita un número entero al usuario y lo escribe en pantalla.
 */
int main() {
    int numero, numero2;

    cout << "Escriba dos números enteros separados por un espacio: ";
    cin >> numero;
    cin >> numero2;

    

    cout << "La suma es " << numero + numero2 << endl;

    return 0;
}
