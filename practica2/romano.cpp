/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
/* 
Programa que solicita por teclado un numero entero desde el 1 al 10 y lo devuelve escrito en numeros romanos.
*/ 
#include <iostream>
#include <math.h> 
#include <wchar.h>



using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {

    int numero;

    cout << "Escriba un entero entre 1 y 10 : " << bold << underline;
    cin >> numero;
    if(numero > 10 || numero < 1) {
        cout << reset << "Datos incorrectos";
        return 1;
    }
    cout << reset << numero << " = ";

    switch (numero) 
    {
    case 1:
        cout << "I";
        break;
    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;
    case 4:
        cout << "IV";
        break;
    case 5:
        cout << "V";
        break;
    case 6:
        cout << "VI";
        break;
    case 7:
        cout << "VII";
        break;
    case 8:
        cout << "VIII";
        break;
    case 9:
        cout << "IX";
        break;
    default:
        cout << "X";
        break;
    }
    
    
    
    return 0;
}
