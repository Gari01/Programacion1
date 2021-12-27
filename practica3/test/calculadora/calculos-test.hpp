/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 8 de octubre de 2021
 * Resumen: Fichero de interfaz de un módulo auxiliar «calculos-test» que
 *          hace pruebas de unidad de las funciones del módulo «calculos».
 ******************************************************************************/

#pragma once

/*
 * Pre:  «valorEsperado» es true si y solo si «n» es un número capicúa.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esCapicua», invocada con el argumento «n», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarEsCapicua(int n, bool valorEsperado);

/*
 * Pre:  «valorEsperado» es el mínimo común múltiplo de «n» y «m».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «mcm», invocada con los argumentos «n» y «m», ha devuelto el valor
 *       correcto «valorEsperado». En caso negativo, ha informado
 *       también acerca del valor incorrecto que devolvió la función.
 */
void probarMcm(int n, int m, unsigned valorEsperado);

