/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 
/***
 * Programa simple que simula una calculadora que solo puede realizar la suma, resta, multiplicación, division y obtener el resto
 * de una division
 */


using namespace std;
#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {
    double operador1 = 0;
    double operador2 = 0;
    char simbolo;

    do
    {
        cout << "Por favor escriba la operacion junto a los dos numeros " << bold << underline;
        cin >> operador1 ;
        if (operador1 != 0)
        {
            cin >> simbolo >> operador2;
           
            if (simbolo == '+') {
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << operador1 + operador2<< endl;
            } else if(simbolo == '-'){
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << operador1 - operador2<< endl;
            } else if(simbolo == '*'){
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << operador1 * operador2<< endl;
            } else if(simbolo == '/'){
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << operador1 / operador2<< endl;
            } else if(simbolo == '%'){
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << int(operador1) % int(operador2) << endl;
            } else if(simbolo == '^'){
                cout << reset << operador1 << " " << simbolo << " " <<  operador2 << " = " << pow(operador1, operador2)<< endl; 
            } else{
                cout << reset << "Ha introducido un simbolo no reconocido"<< endl;
            }
                
        }
    } while (operador1 != 0);

    return 0;
}
