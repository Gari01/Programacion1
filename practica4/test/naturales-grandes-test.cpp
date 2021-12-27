/******************************************************************************\
 * Programación 1. Práctica 4
 * Autor: Miguel Ángel Latre Abadía
 * Ultima revisión: 31 de octubre de 2020
 * Resumen: Fichero de implementación «naturales-grandes-test.cpp» de un módulo
 *          denominado «naturales-grandes-test» para hacer de pruebas de las 
 *          funciones definidas en el módulo «naturales-grandes» de la 4.ª 
 *          práctica.
\******************************************************************************/

#include <iostream>
#include <string>
#include "testing-prog1.hpp"
#include "naturales-grandes.hpp"
using namespace std;

/******************************************************************************\
 * Funciones para probar las funciones nuevas de la biblioteca «calculos» 
 *                                                                        
 * (Para escribir estas funciones, no se ha utilizado conceptos de C++    
 * que no se hayan visto en la asignatura, excepto en las función de conversión 
 * de cadena de caracteres a «natural grande» y viceversa, cuyos conceptos se
 * verán en el tema 10 sobre cadenas de caracteres)                                
 ******************************************************************************/


/*
 * Pre:  «numero» almacena la representación de un número natural. Sea «n» el 
 *       número de dígitos de «numero». La componente numero[0] representa las  
 *       unidades de «numero», la componente numero[1] las decenas de «numero» 
 *       y así, sucesivamente, la componente numero[s-1] representa el dígito 
 *       más significativo de «numero». Las componentes de índices superiores
 *       almacenan el valor 0.
 * Post: Al acabar la ejecución de esta función, esta ha devuelto una cadena de
 *       caracteres que representa el número natural representado por «numero» 
 *       (sin ceros a la izquierda).
 */
string convertirAString(const unsigned numero[]) {
    int i = NUM_DIGITOS - 1;
    while (i >= 0 && numero[i] == 0) {
        i--;
    }
    if (i < 0) {
        return "0";
    }
    else {
        string resultado = "";
        while (i >= 0) {
            resultado += numero[i] + '0';
            i--;
        }
        return resultado;
    }
}


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo).
 * Post: Tras ejecutar esta función, «numeroGrande» contiene la secuencia de 
 *       dígitos equivalente a la de número «numero». Sea «n» el número de
 *       dígitos de «numero». La componente numeroGrande[0] almacena las 
 *       unidades de «numero», la componente numeroGrande[1], las decenas de 
 *       «numero» y así, sucesivamente, la componente numeroGrande[n-1] almacena  
 *       el dígito más significativo de «numero». Las componentes de índices 
 *       superiores almacenan el valor 0
 */
void convertirDeString(const string numeroStr, unsigned numeroGrande[]) {
    for(unsigned i = 0; i < numeroStr.length(); i++) {
        numeroGrande[numeroStr.length() - i - 1] = numeroStr.at(i) - '0';
    }
    for (unsigned i = numeroStr.length(); i < NUM_DIGITOS; i++) {
        numeroGrande[i] = 0;
    }
}


/*
 * Pre:  ---
 * Post: Ha inicializado las NUM_DIGITOS componentes de «numeroGrande» con el 
 *       valor 4 para maximizar las posibilidades de localizar errores.
 */
void inicializar(unsigned numeroGrande[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++) {
        numeroGrande[i] = 4;
    }
}

/*
 * Pre:  «valorEsperado» es una cadena de caracteres que contiene la 
 *       representación decimal de un número natural (sin signo).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «convertir», invocada con el argumento «n», ha calculado el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que calculó la función.
 */
void probarConvertir(const unsigned n, const string valorEsperado) {
    cout << "Prueba convertir (" << n << ", unsigned[]) ";
    unsigned valorCalculado[NUM_DIGITOS];
    inicializar(valorCalculado);
    convertir(n, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado));
}

/*
 * Pre:  «aStr», «bStr» y «valorEsperado» son cadenas de caracteres que contiene 
 *       la representación decimal de números naturales (sin signo).
 *       «valorEsperado», en particular, representa la suma de «aStr» y «bStr».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «sumar», invocada con los argumentos «aStr» y «bStr», ha calculado el 
 *       valor correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que calculó la función.
 */
void probarSumar(const string aStr, const string bStr, 
                 const string valorEsperado) {
    cout << "Prueba sumar (" << aStr << ", " << bStr << ", unsigned[]) ";
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS], valorCalculado[NUM_DIGITOS];
    convertirDeString(aStr, a);
    convertirDeString(bStr, b);
    inicializar(valorCalculado);
    sumar(a, b, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado));
}


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el valor 
 *       numérico representado por la secuencia «numero».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «valor», invocada con el argumento «numero», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado también acerca
 *       del valor incorrecto que devolvió la función.
 */
void probarValor(const string numero, const unsigned valorEsperado) {
   cout << "Prueba valor(" << numero << ") ";
   unsigned numeroGrande[NUM_DIGITOS];
   convertirDeString(numero, numeroGrande);
   unsigned valorDevuelto = valor(numeroGrande);
   escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es la
 *       representación de «numero», pero con sus cifras en orden inverso.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «calcularImagen», invocada con el argumento «numero», ha calculado el
 *       valor correcto «valorEsperado». En caso negativo, ha informado también
 *       acerca del valor incorrecto que devolvió la función.
 */
void probarCalcularImagen(const string numero, const string valorEsperado) {
    cout << "Prueba calcularImagen (" << numero << ", unsigned[]) ";
    unsigned numeroGrande[NUM_DIGITOS], valorCalculado[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    inicializar(valorCalculado);
    calcularImagen(numeroGrande, valorCalculado);
    escribirResultadoPrueba(valorEsperado, convertirAString(valorCalculado));
}


/*
 * Pre:  «numero» almacena una cadena de caracteres con la secuencia de
 *       dígitos de un número natural. «valorEsperado» indica si la secuencia
 *       «numero» corresponde a un número capicúa («true») o no («false»).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esCapicua», invocada con el argumento «numero», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado también acerca
 *       del valor incorrecto que devolvió la función.
 */
void probarEsCapicua(const string numero, const bool valorEsperado) {
    cout << "Prueba esCapicua (" << numero << ") ";
    unsigned numeroGrande[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    bool valorCalculado = esCapicua(numeroGrande);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
}


/*
 * Pre:  «numeroStr» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo).
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «copiar», invocada con el argumento «numeroStr», ha realizado una copia
 *       correcta de su argumento de entrada. En caso negativo, ha informado 
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarCopiar(const string numeroStr) {
    cout << "Prueba copiar (" << numeroStr << ", unsigned[]) ";
    unsigned numeroGrande[NUM_DIGITOS], valorCalculado[NUM_DIGITOS];
    convertirDeString(numeroStr, numeroGrande);
    inicializar(valorCalculado);
    copiar(numeroGrande, valorCalculado);
    escribirResultadoPrueba(convertirAString(numeroGrande),
                            convertirAString(valorCalculado));
}


/*
 * Pre:  «aStr» y «bStr» son cadenas de caracteres que contienen la  
 *       representación decimal de dos números naturales (sin signo). 
 *       «valorEsperado» es igual a true si «aStr» y «bStr» es la representación
 *       del mismo número y false en caso contrario.
 */
void probarSonIguales(const string aStr, const string bStr, 
                      const bool valorEsperado) {
    cout << "Prueba sonIguales (" << aStr << ", " << bStr << ") ";
    unsigned a[NUM_DIGITOS], b[NUM_DIGITOS];
    convertirDeString(aStr, a);
    convertirDeString(bStr, b);
    bool valorCalculado = sonIguales(a, b);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
      
}


/*
 * Pre:  «numero» es una cadena de caracteres que contiene la representación
 *       decimal de un número natural (sin signo). «valorEsperado» es el número
 *       de cifras de «numero».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «numCifras», invocada con el argumento «numero», ha calculado el
 *       valor correcto «valorEsperado». En caso negativo, ha informado también
 *       acerca del valor incorrecto que devolvió la función.
 */
void probarNumCifras(const string numero, const unsigned valorEsperado) {
    cout << "Prueba numCifras (" << numero << ") ";
    unsigned numeroGrande[NUM_DIGITOS];
    convertirDeString(numero, numeroGrande);
    unsigned valorCalculado = numCifras(numeroGrande);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
}