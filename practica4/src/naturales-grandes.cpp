/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: ------------- Gari Arellano Zubía -------------
 * Ultima revisión: 
 * Resumen: Fichero de implementación «naturales-grandes.cpp» de un módulo
 *          denominado «naturales-grandes» para trabajar con números naturales 
 *          de gran magnitud en la 4ª práctica.
\******************************************************************************/
#include <iostream>
#include <cmath>
#include "naturales-grandes.hpp"
using namespace std;
/*
 * Pre:  «original» almacena la representación de un número natural. La
 *       componente original[0] representa   
 *       las unidades de «original», la componente original[1] las decenas de  
 *       «original» y así, sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «original» y «copia» tienen 
 *       «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar esta función, «copia» almacena una representación
 *       idéntica a la del número natural correspondiente a la de «original».
 */
void copiar(const unsigned int original[], unsigned int copia[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++)
    {
        copia[i] = original[i];
    }
    
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales. 
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y 
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así 
 *       sucesivamente. Las componentes de índices
 *       superiores a los correspondientes a los dígitos más significativos
 *       almacenan el valor 0. Las componentes de 
 *       índices superiores almacenan el valor 0. «a» y «b» tienen «NUM_DIGITOS»
 *       componentes.
 * Post: Al acabar la ejecución de esta función, esta ha devuelto el valor 
 *       booleano true si «a» y «b» representan el mismo número natural y false
 *       en caso contrario.
 */
bool sonIguales(const unsigned int a[], const unsigned int b[]) {
    for (unsigned i = 0; i < NUM_DIGITOS; i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}


/*
 * Pre:  «natural» almacena la representación de un número natural. La 
 *       componente natural[0] representa las unidades de «natural», la
 *       componente natural[1] las decenas de «natural» y así, sucesivamente. 
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0. «natural» tiene «NUM_DIGITOS»
 *       componentes.
 * Post: Al acabar la ejecución de esta función, esta ha devuelto el número de
 *       cifras de «natural» cuando se escribe en base 10 sin ceros a la
 *       izquierda.
 */
unsigned int numCifras(const unsigned int natural[]) {
    for (int i = NUM_DIGITOS - 1; i >= 0; i--)
    {
        if(natural[i] != 0)
        {
            return i + 1;
        }
    }
    return 1;
}
/*
 * Pre:  «natural» almacena la representación de un número natural grande. Sea 
 *       «n» el número de dígitos de «natural». La componente natural[0] 
 *       representa las unidades de «natural», la componente natural[1] las
 *       decenas de «natural» y así, sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar esta función, se ha escrito en la pantalla el número 
 *       natural representado por «natural» (sin ceros a la izquierda).
 */
void escribirEnPantalla(const unsigned int natural[]) {
    for (int i = numCifras(natural)-1; i >=0; i--)
    {
        cout << natural[i];
    }
}


/*
 * Pre:  «naturalGrande» tiene «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar esta función, «naturalGrande» contiene la secuencia de 
 *       dígitos equivalente a «numero». 
 *       La componente naturalGrande[0] almacena las unidades de «numero», la
 *       componente naturalGrande[1], las decenas de «numero» y así 
 *       sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0.
 */
void convertir(const unsigned int numero, unsigned int naturalGrande[]) {
    unsigned int numero2 = numero;
    for (int i = 0; i < numCifras(naturalGrande); i++)
    {
        naturalGrande[i] = (numero2 % 10);
        numero2 = numero2 / 10;
    }
}


/*
 * Pre:  «naturalGrande» almacena los dígitos de un número natural lo 
 *       suficientemente pequeño como para ser representado por un dato de tipo
 *       «unsigned int». En la componente naturalGrande[0] se almacena el dígito
 *       que representa las unidades de ese número, en la componente 
 *       naturalGrande[1], las decenas y así sucesivamente. Las componentes de
 *       índices superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «naturalGrande» tiene 
 *       «NUM_DIGITOS» componentes.
 * Post: Al acabar la ejecución de esta función, esta ha devuelto el valor
 *       numérico del natural almacenado en «naturalGrande».
 */
unsigned int valor(const unsigned int naturalGrande[]) {
    int valor = naturalGrande[0];
    int posicion = 10;
    for (int i = 1; i < numCifras(naturalGrande); i++)
    {
        valor = valor + (naturalGrande[i] * posicion);
        posicion = posicion * 10;  
    }
    return valor;
}


/*
 * Pre:  «a» y «b» almacenan las representaciones de sendos números naturales. 
 *       Sea «n» el número de dígitos de «a» y «m» el número de dígitos de «b». 
 *       Las componentes a[0] y b[0] representan las unidades del natural «a» y 
 *       «b», respectivamente, las componentes a[1] y b[1], las decenas y así 
 *       sucesivamente. Las componentes de índices
 *       superiores a los correspondientes a los dígitos más significativos
 *       almacenan el valor 0. La suma de los números
 *       representados por «a» y «b» tiene menos de «NUM_DIGITOS» dígitos.
 *       Los vectores «a», «b» y «suma» tienen «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar esta función, «suma» almacena la representación de un
 *       número natural equivalente a la suma de los naturales representados por
 *       «a» y «b». Sea «s» el número de dígitos de suma. La componente suma[0]
 *       representa las unidades de la suma, la componente suma[1] representa
 *       las decenas y así sucesivamente.
 */
void sumar(const unsigned int a[], const unsigned int b[], unsigned int suma[]) {
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
       suma[i] = 0;
    }
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
        if((a[i] + b[i] + suma[i]) >= 10) 
        {
            suma[i+1] = 1; 
            suma[i] = (a[i] + b[i] + suma[i]) - 10;
        } else 
        {
            suma[i] = a[i] + b[i] + suma[i];
        }
    }
}
/*
 * Pre:  «natural» almacena la representación de un número natural. La componente
 *       natural[0] representa las unidades de «natural», la componente natural[1]
 *       las decenas de «natural» y así sucesivamente. Las componentes de 
 *       índices superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «natural» e «imagen» tienen «NUM_DIGITOS» 
 *       componentes.
 * Post: Tras ejecutar esta función, «imagen» almacena la representación del 
 *       número natural correspondiente a la imagen especular de «natural».
 */
void calcularImagen(const unsigned int natural[], unsigned int imagen[]) {
    for (int i = 0; i < NUM_DIGITOS; i++)
    {
       imagen[i] = 0;
    }
    for (int i = 0; i < numCifras(natural); i++)
    {
        imagen[i] = natural[numCifras(natural) - i - 1];
    }
}
/*
 * Pre:  «natural» almacena la representación de un número natural. La componente
 *       natural[0] representa las unidades de «natural», la componente natural[1]
 *       las decenas de «natural» y así sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Ha devuelto «true» si y solo si «natural» es un número capicúa.
 */
bool esCapicua(const unsigned int natural[]) {
    unsigned imagen[NUM_DIGITOS]; 
    calcularImagen(natural,imagen);
    return sonIguales(natural,imagen);
}

