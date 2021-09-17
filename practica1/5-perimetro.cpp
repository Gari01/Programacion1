/*******************************************************************************
 * Curso de Programación 1. Tema 1
 * Autores: Miguel Ángel Latre
 * Última revisión: 14 de septiembre de 2021
 * Resumen: Programa que solicita al usuario el número de lados de un polígono
 *          regular y la longitud de sus lados y escribe en la pantalla el área 
 *          de dicho polígono regular.
 ******************************************************************************/
#include <iostream>
using namespace std;

/*
 * Dado un polígono regular con un número de lados igual al valor del parámetro 
 * «numLados» de longitud igual al valor del parámetro «longitud», devuelve el
 * perímetro de dicho polígono regular. «numLados» tiene que ser mayor o igual 
 * que 3 y «longitud» mayor que 0.0.
 */
double perimetro(int numLados, double longitud) {
    return numLados * longitud;
}

/*
 * Programa que solicita al usuario el número de lados de un polígono regular y 
 * la longitud de sus lados y escribe en la pantalla el área de dicho polígono
 * regular.
 */
int main() {
    cout << "Escriba el número de lados: ";
    int numLados;
    cin >> numLados;

    cout << "Escriba la longitud del lado: ";
    double longitud;
    cin >> longitud;

    cout << "El perímetro de un polígono regular de " << numLados
         << " lados de longitud " << longitud << " es " 
         << perimetro(numLados, longitud) << "." << endl;

    return 0;
}
