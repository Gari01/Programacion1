/*******************************************************************************
 * Curso de Programación 1. Prácticas
 * Autores: Miguel Ángel Latre
 * Última revisión: 18 de octubre de 2020
 * Resumen: Fichero de implementación de un módulo auxiliar
 *          «testing» que escribe en la pantalla los resultados de realizar
 *          pruebas de unidad de algunas funciones del módulo «calculos» y 
 *          «fechas» de esta práctica y de otros módulos en prácticas
 *          posteriores.
 *          Para escribir estas funciones, solo se han utilizado
 *          conceptos de C++ que se han visto en la asignatura (excepto las
 *          secuencias de escape utilizadas para escribir en rojo los mensajes
 *          correspondientes a pruebas en las que se detectan errores). Es por
 *          ello que hay mucho código repetido, ya que las estructuras
 *          de las funciones se repiten.
 ******************************************************************************/

#include <iostream>
#include <string>
#include "testing-prog1.hpp"
using namespace std;

/* 
 * Constantes que definen las secuencias de escape que permiten escribir
 * mensajes en la pantalla en color rojo, rojo con negrita y normal.
 */
const string ESCAPE_ROJO = "\033[31m";
const string ESCAPE_ROJO_NEGRITA = "\033[31;1m";
const string ESCAPE_NORMAL = "\033[0m";

/*
 * Especificación común a TODAS las funciones definidas en este fichero de
 * cabecera
 * 
 * Pre:  En la línea actual de la pantalla se ha escrito un texto anunciando que
 *       se ha realizado una prueba de una determinada función con unos
 *       determinados argumentos.
 * Post: Si los valores de «valorEsperado» y «valorCalculado» son iguales, ha
 *       completado un mensaje en la pantalla informando de que la prueba ha
 *       sido correcta. En caso contrario, indica que ha sido incorrecta y ha
 *       informado también de los valores de «valorEsperado» y «valorCalculado».
 */

/*
 * Versión de la función para datos de tipo «int»
 */
void escribirResultadoPrueba(const int valorEsperado, const int valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << valorEsperado
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << valorCalculado 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}


/*
 * Versión de la función para datos de tipo «unsigned»
 */
void escribirResultadoPrueba(const unsigned valorEsperado, 
                             const unsigned valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << valorEsperado
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << valorCalculado 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}


/*
 * Versión de la función para datos de tipo «bool»
 */
void escribirResultadoPrueba(const bool valorEsperado, const bool valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << boolalpha;
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << valorEsperado
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << valorCalculado 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}

/*
 * Versión de la función para datos de tipo «double»
 */
void escribirResultadoPrueba(const double valorEsperado,
                             const double valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << valorEsperado
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << valorCalculado 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}


/*
 * Versión de la función para datos de tipo «char»
 */
void escribirResultadoPrueba(const char valorEsperado,
                             const char valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << "'" << valorEsperado << "'" 
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << "'" << valorCalculado << "'" 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}

/*
 * Versión de la función para datos de tipo «string»
 */
void escribirResultadoPrueba(const string valorEsperado,
                             const string valorCalculado) {
    if (valorEsperado == valorCalculado) {
        cout << "correcta." << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << ESCAPE_ROJO;
        cout << "   debería haber obtenido " 
             << ESCAPE_ROJO_NEGRITA << "\"" << valorEsperado << "\"" 
             << ESCAPE_NORMAL << ESCAPE_ROJO 
             << " pero ha calculado " 
             << ESCAPE_ROJO_NEGRITA << "\"" << valorCalculado << "\"" 
             << ESCAPE_NORMAL << ESCAPE_ROJO << '.' << endl;
        cout << ESCAPE_NORMAL;
    }
}