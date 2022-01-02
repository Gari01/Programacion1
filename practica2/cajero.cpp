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
    int billetesDe50 = 0;
    int billetesDe20 = 0;
    int billetesDe10 = 0;
    int ancho = 7;

    cout << "Cantidad a retirar en euros [positiva y múltiplo de 10]: "<< bold << underline;
    cin >> dinero;
    if(dinero < 0 || dinero%10 !=0 || dinero>600) {
        cout << reset << "Datos erroneos";
        return 1;
    } else {
        billetesDe50 = dinero/50;
        billetesDe20 = (dinero%50)/20;
        billetesDe10 = ((dinero%50)%20)/10;

        cout << reset << setw(ancho) << "Billetes" << setw(ancho) << "Euros" << endl 
        << setw(ancho) << "========" << setw(ancho) << "=====" << endl 
        << setw(ancho) << billetesDe10 << setw(ancho) << "10" << endl
        << setw(ancho) << billetesDe20 << setw(ancho) << "20" << endl
        << setw(ancho) << billetesDe50 << setw(ancho) << "50" << endl;
    }
    
    return 0;
}

