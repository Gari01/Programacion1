/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
/* 
Programa que solicita por teclado las coordenadas X e Y de dos puntos y calcula la distancia Euclidea que existe entre los puntos.
*/
#include <iostream>
#include <math.h> 
#include <iomanip>



using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"

/* 
Función para calcular la distancia Euclidea, entre dos puntos, recibe por parametros las coordenadas X e Y de ambos puntos 
y devuelve la distancia.
*/
double distanciaEuclidea(double puntoXA, double puntoYA, double puntoXB, double puntoYB) {
    return sqrt(pow(puntoXB - puntoXA,2) + pow(puntoYB - puntoYA,2));
}

int main() {

    double puntoXA;
    double puntoXB;
    double puntoYA;
    double puntoYB;
    double distancia;

    cout << "Introduzca las coordenadas de un punto: ";
    cin >> puntoXA >> puntoYA;
    cout << "Introduzca las coordenadas de otro punto: ";
    cin >> puntoXB >> puntoYB;

    cout << "La distancia entre los puntos es de " << setprecision(5) << distanciaEuclidea(puntoXA, puntoYA, puntoXB, puntoYB) << " unidades";
    
    return 0;
}

