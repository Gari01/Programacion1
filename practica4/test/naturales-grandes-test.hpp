/******************************************************************************\
 * Programación 1. Práctica 4
 * Autor: Miguel Ángel Latre Abadía
 * Ultima revisión: 10 de noviembre de 2018
 * Resumen: Fichero de interfaz «naturales-grandes-test.h» de un módulo
 *          denominado «naturales-grandes-test» para hacer de pruebas de las
 *          funciones definidas en el módulo «naturales-grandes» de la
 *          4ª práctica.
 * Codificación de caracteres original de este fichero: UTF-8 con BOM
\******************************************************************************/

#include <string>
using namespace std;

/*
 * Pre:  «valorEsperado» es una cadena de caracteres que contiene la 
 *       representación decimal de un número natural (sin signo).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «convertir», invocada con el argumento «n», ha calculado el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que calculó la función.
 */
void probarConvertir(const unsigned n, const string valorEsperado);

/*
 * Pre:  «a», «b» y «valorEsperado» son cadenas de caracteres que contienen la 
 *       representación decimal de números naturales (sin signo).
 *       «valorEsperado», en particular, representa la suma de «a» y «b».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «sumar», invocada con los argumentos «a» y «b», ha calculado el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que calculó la función.
 */
void probarSumar(const string a, const string b, const string valorEsperado);


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el valor 
 *       numérico representado por la secuencia «numero».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «valor», invocada con el argumento «numero», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado también acerca
 *       del valor incorrecto que devolvió la función.
 */
void probarValor(const string numero, const unsigned valorEsperado);


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es la
 *       representación de «numero», pero con sus cifras en orden inverso.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «calcularImagen», invocada con el argumento «numero», ha calculado el
 *       valor correcto «valorEsperado». En caso negativo, ha informado también
 *       acerca del valor incorrecto que devolvió la función.
 */
void probarCalcularImagen(const string numero, const string valorEsperado);


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» indica si 
 *       «numero» representa un número capicúa («true») o no («false»).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esCapicua», invocada con el argumento «numero», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado también acerca
 *       del valor incorrecto que devolvió la función.
 */
void probarEsCapicua(const string numero, const bool valorEsperado);


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «copiar», invocada con el argumento «numero», ha realizado una copia
 *       correcta de su argumento de entrada. En caso negativo, ha informado 
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarCopiar(const string numero);


/*
 * Pre:  «a» y «b» son cadenas de caracteres que contienen la representación 
 *       decimal de dos números naturales (sin signo). «valorEsperado» es igual
 *       a true si «a» y «b» es la representación del mismo número y false en
 *       caso contrario.
 */
void probarSonIguales(const string a, const string b, const bool valorEsperado);


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el número
 *       de cifras de «numero».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «numCifras», invocada con el argumento «numero», ha calculado el
 *       valor correcto «valorEsperado». En caso negativo, ha informado también
 *       acerca del valor incorrecto que devolvió la función.
 */
void probarNumCifras(const string numero, const unsigned valorEsperado);