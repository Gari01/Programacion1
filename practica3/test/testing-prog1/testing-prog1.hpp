/*******************************************************************************
 * Curso de Programación 1. Prácticas
 * Autores: Miguel Ángel Latre
 * Última revisión: 8 de octubre de 2021
 * Resumen: Fichero de cabecera de un módulo auxiliar
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

#include <string>
using namespace std;

#pragma once

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
void escribirResultadoPrueba(const int valorEsperado, const int valorCalculado);

/*
 * Versión de la función para datos de tipo «unsigned»
 */
void escribirResultadoPrueba(const unsigned valorEsperado,
                             const unsigned valorCalculado);

/*
 * Versión de la función para datos de tipo «bool»
 */
void escribirResultadoPrueba(const bool valorEsperado,
                             const bool valorCalculado);

/*
 * Versión de la función para datos de tipo «double»
 */
void escribirResultadoPrueba(const double valorEsperado,
                             const double valorCalculado);
/*
 * Versión de la función para datos de tipo «char»
 */
void escribirResultadoPrueba(const char valorEsperado,
                             const char valorCalculado);

/*
 * Versión de la función para datos de tipo «string»
 */
void escribirResultadoPrueba(const string valorEsperado,
                             const string valorCalculado);
