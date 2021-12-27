/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: ------------- Gari Arellano Zubía -------------
 * Ultima revisión: 
 * Resumen: 
\******************************************************************************/
#include <iostream>
#include "naturales-grandes.hpp"
using namespace std;
/*
 * Pre:  «numero» almacena el numero natural que se debe evaluar para determinar si es o no un numero de Lychrel. 
 * Post: Tras ejecutar esta función, se ha escrito en pantalla un mensaje solicitando un numero natural, y se ha guardado en la variable
 * numero.
 */
void pedirDatos(unsigned int& numero){
    cout << "Escriba un número natural:";
    cin >> numero;
}
/*
 * Programa simple que solicita por teclado un numero natural y nos devuelve si es o no un numero de Lychrel. Mostrando todas las operaciones
 * que realiza por pantalla.
 */
int main() {

    unsigned int numero, i = 1;
    unsigned Operando1[NUM_DIGITOS]; // Creo un vector para el operador1 de la suma.
    unsigned Operando2[NUM_DIGITOS]; // Creo un vector para el operador2 de la suma.
    unsigned Resultado[NUM_DIGITOS]; // Creo un vector para el resultado de la suma.
    pedirDatos(numero);
    convertir(numero,Operando1); // Como la primera vez, el programa solo imprime el numero escrito por teclado, lo saco del bucle.
    cout << "Iteración 0: " << numero << endl;
    while (!esCapicua(Operando1))
    {
        cout << "Iteración " << i << ": ";
        calcularImagen(Operando1,Operando2); // Calculamos la imagen y la guardamos en un vector
        sumar(Operando1,Operando2,Resultado); // Realizamos la suma del numA y el numB y lo guardamos en un vector.
        // Comparo el numero digitos de los vectores
        if (numCifras(Operando1) < 20 || numCifras(Operando1) > NUM_DIGITOS - 1 )
        {
            escribirEnPantalla(Operando1); // Escribimos en pantalla el numero.
            cout << " + ";
            escribirEnPantalla(Operando2);
            cout << " = ";
            escribirEnPantalla(Resultado);
        }
        cout << endl;
        copiar(Resultado,Operando1); // Copiamos el valor de la suma de A+B en el vector del numero A, ya que obtiene el valor de la suma anterior.
        i++;
        // Comparo el numero de digitos, y si es igual a NUM_DIGITOS, imprimo por pantalla un mensaje y finalizo el programa.
        if(numCifras(Operando1) == NUM_DIGITOS)
        {
            cout << numero << " podria ser un número de Lychrel.";
            return 0;
        }
    }
    cout << numero << " no es un número de Lychrel.";
    return 0;
}
