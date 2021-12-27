/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Gari Arellano Zubía
 * Última revisión: 21 de octubre de 2021
 * Resumen: Programa que escribe en la pantalla el calendario de un determinado
 *          mes de un año, que se solicitan al usuario. El programa se asegura
 *          de que el mes introducido está comprendido entre 1 y 12 y de que el
 *          año es igual o posterior a 1900.
 *          Clase de problemas correspondiente al tema 7 (diseño modular y
 *          descendente) y 3ª práctica.
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
\******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "fechas.hpp"
using namespace std;

/*
 * Pre:  
 * Post: Solicita que se introduzca un mes comprendido entre el 1 y el 12 y si el mes es correcto, solicita que se introduzca
 * un año que sea mayor a 1900, en caso de que el año sea incorrecto, se volvera a solicitar.
 */
void pedirDatos(unsigned& mes, unsigned& agno) {
    cout << "Introduzca el mes [1-12]: ";
    cin >> mes;
    while (mes < 1 || mes > 12) 
    {
        cout << "El mes debe estar comprendido entre 1 y 12: ";
        cin >> mes;
    }
    cout << "El año debe ser igual o posterior a 1900: ";
    cin >> agno;
    while(agno < 1900)
    {
        cout << "El año debe ser igual o posterior a 1900: ";
        cin >> agno;
    }
}


/*
 * Pre:  1 ≤ mes ≤ 12
 * Post: Ha escrito en la pantalla el nombre (en mayúsculas) del mes
 *       correspondiente al valor del parámetro «mes».
 * Nota: Este código lo podrás comprender adecuadamente cuando hayamos visto
 *       los temas 9 (vectores) y 10 (cadenas de caracteres).
 */
void escribirNombreMes(unsigned mes) {
    const string NOMBRES_MES[12] = { "ENERO",
            "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO",
            "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };
    cout << NOMBRES_MES[mes - 1];
}
/*
 * Pre:  
 * Post: Se imprime en pantalla la cabecera del calendario, indicando el mes y el año.
 */
void escribirCabecera(unsigned mes, unsigned agno) {
    cout << setw(23);
    escribirNombreMes(mes);
    cout << setw(6) << agno << endl;
    cout << setw(4) << "L" << setw(4) << "M" << setw(4) << "X" << setw(4) << "J" << setw(4) << "V" << setw(4) << "S" << setw(4) << "D" << endl
    << "------------------------------" << endl;
}
/*
 * Pre:  
 * Post: Se imprime en pantalla el calendario completo del mes y año elegido por el usuario.
 */
void escribirDias(unsigned mes, unsigned agno) {
    escribirCabecera(mes, agno);
    diaDeLaSemana(1, mes, agno);
    cout << setw(4*(diaDeLaSemana(1, mes, agno)+1)) << "1";
    for (int i = 2; i <= diasDelMes(mes, agno); i++)
    {   
        cout << setw(4) << i;
        if(diaDeLaSemana(i, mes, agno)==6) // Imprimo un salto de linea cuando finaliza la semana.
        {
            cout << endl;
        }
    }
}
/*
 * Programa que solicita por teclado un mes y un año, para imprimir por pantalla un calendario 
 * del mes y año que se ha introducido previamente.
 * 
 */
int main() {
    unsigned mes, agno;

    pedirDatos(mes, agno);
    escribirDias(mes, agno);
    return 0;
}
