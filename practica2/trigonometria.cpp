/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 
#include <iomanip>
/* 
Programa que solicita por teclado el valor de un angulo en grados, minutos y segundos y calcula su valor en radianes, ademas de su 
seno, coseno y tangente.
*/


using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {

    int grados;
    int minutos;
    int segundos;
    double radianes;
    int decimales = 5;

    cout << "Escriba el valor de un ángulo (grados, minutos y segundos): " << bold << underline;
    cin >> grados >> minutos >> segundos;
    if(grados < 0 || minutos < 0 || segundos < 0 || grados > 359 || minutos > 59 || segundos > 59) {
        cout << reset << "Datos incorrectos";
        return 1;
    }
    

    grados = grados + (minutos + segundos/60) / 60;
    if(grados == 90 || grados == 270 ){
        cout << reset << "";
    } else {
        radianes = grados * M_PI/180;

        cout << reset << "Valor del angulo en radianes: " <<  setprecision(decimales) << radianes << " radianes" << endl;
        cout  << "sen " << radianes << " = " << setprecision(decimales) << sin(radianes)<< endl;
        cout << "cos " << radianes << " = " << setprecision(decimales) << cos(radianes)<< endl;
        cout << "tg " << radianes << " = " << setprecision(decimales) << tan(radianes)<< endl;
    }
    
    
    return 0;
}
