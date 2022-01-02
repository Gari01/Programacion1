/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 

/* 
Programa que solicita por teclado una cantidad de segundos y devuelve a cuantos dias, hora, minutos y segundos equivalen.
*/



using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {

    int segundos;
    int dias = 0;
    int horas = 0;
    int minutos = 0;
    // Utilizo las variables dias, horas y minutos como contadores.


    cout << "Duración en segundos: " << bold << underline;
    cin >> segundos;

    if(segundos < 0) {
        cout << reset << "Datos incorrectos";
        return 1;
    } else {
        dias = segundos/86400;
        horas = (segundos%86400)/3600;
        minutos = ((segundos%86400)%3600)/60;
        segundos = ((segundos%86400)%3600)%60;
        cout << reset << "Este tiempo equivale a " << dias << " dias " << horas << " horas " << minutos << " minutos " << segundos << " segundos.";
    }
    
    
    
    return 0;
}
