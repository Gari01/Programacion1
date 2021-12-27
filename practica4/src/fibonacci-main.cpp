/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: ------------- Gari Arellano Zubía-------------
 * Ultima revisión: 
 * Resumen: 
\******************************************************************************/
#include <iostream>
#include "naturales-grandes.hpp"
using namespace std;

/*
 * Pre:   NumInicial es mayor que 0.
 * Post: Tras ejecutar esta función, se imprime en pantalla la sucesion de Fibonacci, iniciando desde NumInicial hasta NumFinal.
 */
void calcularFibonacci(const int numInicial, const int numFinal){
    unsigned numero[NUM_DIGITOS];
    unsigned elemento[NUM_DIGITOS] = {0};
    unsigned elementoSiguiente[NUM_DIGITOS] = {1};
    int i = 0;
    while (i<numFinal)
    {
        sumar(elemento, elementoSiguiente, numero);
        if (i >= numInicial - 1)
        {
            cout << i + 1 << ". ";
            escribirEnPantalla(elemento);
            cout << endl;
        }
        copiar(elementoSiguiente, elemento);
        copiar(numero,elementoSiguiente);
        i++;
    }
    
}

/***
 * Programa simple que solicita por teclado dos numeros e imprime por pantalla la sucesion de Fibonacci, delimitada por los dos numeros 
 * introducidos por el usuario.
 */
int main() {
    int numInicial, numFinal;
    while (true)
    {
        cout << "Términos inicial y final (0 o negativo para acabar): ";
        cin >> numInicial;
        if(numInicial <= 0) 
        {
            return 0;
        }
        cin >> numFinal;
        calcularFibonacci(numInicial,numFinal);
    }
}
