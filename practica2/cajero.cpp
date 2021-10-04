/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 
#include <iomanip>
/* 
    Programa que simula un cajero, al que nosotros le introducimos una cantidad positiva que sea multiplo de 10
    y el programa nos devuelve cuantos billetes de 10, 20 y 50 se nos devuelven.
*/


using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"


int main() {

    unsigned int dinero;
    int acumulador10 = 0;
    int acumulador20 = 0;
    int acumulador50 = 0;
    int ancho = 7;

    cout << "Cantidad a retirar en euros [positiva y múltiplo de 10]: "<< bold << underline;
    cin >> dinero;

    if(dinero < 0) {
        cout << "Datos erroneos";
    } else {
        while (dinero >= 10) {
            if(dinero >= 50) {
                dinero = dinero - 50;
                acumulador50++;
            } else if (dinero >= 20) {
                        dinero = dinero - 20;
                        acumulador20++;
                    } else if (dinero >= 10) {
                                dinero = dinero - 10;
                                acumulador10++;
                            }
        }
    }
    
    cout << reset << setw(ancho) << "Billetes" << setw(ancho) << "Euros" << endl 
    << setw(ancho) << "========" << setw(ancho) << "=====" << endl 
    << setw(ancho) << acumulador10 << setw(ancho) << "10" << endl
    << setw(ancho) << acumulador20 << setw(ancho) << "20" << endl
    << setw(ancho) << acumulador50 << setw(ancho) << "50" << endl;

    return 0;
}
