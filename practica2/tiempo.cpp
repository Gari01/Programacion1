/*******************************************************************************
 * Curso de Programación 1. Práctica 2
 * Autores: Gari Arellano Zubía
 * Última revisión: 20 de septiembre de 2021
 ******************************************************************************/
#include <iostream>
#include <math.h> 
#include <wchar.h>



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

    while(segundos > 59) { // Realizo un bucle hasta que los segundos sean un numero mayor que 59.
        if(segundos >= 86400){ // Cada vez que entre en un If incremento en uno los contados asignados.
            segundos = segundos - 86400;
            dias++;
        }else if(segundos >= 3600){
                    segundos = segundos - 3600;
                     horas++;
            } else if(segundos >= 60){
                        segundos = segundos - 60;
                        minutos++;
                    }
    }
    
    cout << reset << "Este tiempo equivale a " << dias << " dias " << horas << " horas " << minutos << " minutos " << segundos << " segundos.";
    
    return 0;
}
