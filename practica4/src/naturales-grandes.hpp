/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Ultima revisión: 31 de octubre de 2020
 * Resumen: Fichero de interfaz «naturales-grandes.hpp» de un módulo denominado
 *          «naturales-grandes» para trabajar con números naturales de gran
 *          magnitud en la 4ª práctica.
 * Nota: Este fichero de interfaz NO debe modificarse.
\******************************************************************************/

#pragma once

const unsigned NUM_DIGITOS = 1000;

/*
 * Pre:  «original» almacena la representación de un número natural. La
 *       componente original[0] representa las unidades de «original», la
 *       componente original[1] las decenas de «original» y así, sucesivamente.
 *       Las componentes de índices superiores al correspondiente al dígito más
 *       significativo almacenan el valor 0. «original» y «copia» tienen 
 *       «NUM_DIGITOS» componentes.
 * Post: Tras ejecutar esta función, «copia» almacena una representación
 *       idéntica a la del número natural correspondiente a la de «original».
 */
void copiar(const unsigned original[], unsigned copia[]);

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
bool sonIguales(const unsigned a[], const unsigned b[]);

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
unsigned numCifras(const unsigned natural[]);

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
void escribirEnPantalla(const unsigned natural[]);

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
void convertir(const unsigned numero, unsigned naturalGrande[]);

/*
 * Pre:  «naturalGrande» almacena los dígitos de un número natural lo 
 *       suficientemente pequeño como para ser representado por un dato de tipo
 *       «unsigned». En la componente naturalGrande[0] se almacena el dígito
 *       que representa las unidades de ese número, en la componente 
 *       naturalGrande[1], las decenas y así sucesivamente. Las componentes de
 *       índices superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «naturalGrande» tiene 
 *       «NUM_DIGITOS» componentes.
 * Post: Al acabar la ejecución de esta función, esta ha devuelto el valor
 *       numérico del natural almacenado en «naturalGrande».
 */
unsigned valor(const unsigned naturalGrande[]);

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
void sumar(const unsigned a[], const unsigned b[], unsigned suma[]);

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
void calcularImagen(const unsigned natural[], unsigned imagen[]);

/*
 * Pre:  «natural» almacena la representación de un número natural. La componente
 *       natural[0] representa las unidades de «natural», la componente natural[1]
 *       las decenas de «natural» y así sucesivamente. Las componentes de índices
 *       superiores al correspondiente al dígito más significativo
 *       almacenan el valor 0. «natural» tiene «NUM_DIGITOS» componentes.
 * Post: Ha devuelto «true» si y solo si «natural» es un número capicúa.
 */
bool esCapicua(const unsigned natural[]);
