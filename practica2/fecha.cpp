/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 * Programa para pasar de una fecha aaaammdd a dd/mm/aaaa
 ******************************************************************************/
/* 
Programa que solicita por teclado una fecha en formato de 8 cifras [aaaammdd] y nos devuelve la fecha escrita en formato dd/mm/aaaa
*/
#include <iostream>
#include <iomanip>

using namespace std;

#define underline "\033[4m"
#define bold "\e[1m"
#define reset "\x1B[0m"




int main() {

    int fecha;
    int dia;
    int mes;
    int anio;
    int auxiliar;
    

    cout << "Escriba una fecha con formato de 8 cifras [aaaammdd]:" << bold << underline; 
    cin >>  fecha;
    if(fecha < 0) {
        cout <<  reset << "Datos incorrectos"<< endl;
        return 1;
    } else {
        anio = fecha/10000; // Divido entre 10.000 para obtener el año.
        auxiliar = fecha%10000; // Guardo en la variable auxiliar el resto, que son el mes y el dia
        mes = auxiliar/100;
        if(mes < 1 || mes > 12){
            cout << reset << "Datos incorrectos"<< endl;
            return 1;
        } else {
            auxiliar = fecha%100; // Ahora auxiliar obtiene el valor de solo el dia
            if(auxiliar<1 || auxiliar > 31) {
                cout << reset << "Datos incorrectos"<< endl;
                return 1;
            }else {
                dia = auxiliar; // Como auxiliar tiene el valor de dia, se lo asigno a dia.
                cout << reset << setfill('0') << setw(2) << dia << "/" << setfill('0') << setw(2) << mes << "/" << anio;
            }
        }
    }
    return 0;
}
