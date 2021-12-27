/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 21 de octubre de 2019
 * Resumen: Módulo principal de un programa que hace pruebas unitarias de
 *          las funciones del módulo «calculos».
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
 ******************************************************************************/

#include <iostream>
#include "calculos-test.hpp"
using namespace std;

/*
 * Programa que realiza pruebas unitarias de las funciones «esCapicua» y «mcm»
 * del módulo de biblioteca «calculos». En cada prueba, se indica los parámetros
 * utilizados y si el resultado ha sido correcto o no. Además, en los casos
 * negativos, indica las salidas realmente proporcionadas por la función y las
 * que debería proporcionar.
 */
int main() {
    probarEsCapicua(0, true);
    probarEsCapicua(1, true);
    probarEsCapicua(-1, true);
    probarEsCapicua(9, true);
    probarEsCapicua(-9, true);
    probarEsCapicua(10, false);
    probarEsCapicua(-10, false);
    probarEsCapicua(11, true);
    probarEsCapicua(-11, true);
    probarEsCapicua(99, true);
    probarEsCapicua(-99, true);
    probarEsCapicua(100, false);
    probarEsCapicua(-100, false);
    probarEsCapicua(1234321, true);
    probarEsCapicua(-1234321, true);
    probarEsCapicua(12344321, true);
    probarEsCapicua(-12344321, true);
    probarEsCapicua(1234329, false);
    probarEsCapicua(-1234329, false);
    probarEsCapicua(12344329, false);
    probarEsCapicua(-12344329, false);
    probarEsCapicua(1234391, false);
    probarEsCapicua(-1234391, false);
    probarEsCapicua(12344391, false);
    probarEsCapicua(-12344391, false);
    probarEsCapicua(1234921, false);
    probarEsCapicua(-1234921, false);
    probarEsCapicua(2147483647, false);
    probarEsCapicua(-2147483647, false);
    probarEsCapicua(2147447412, true);
    probarEsCapicua(-2147447412, true);
    
    probarMcm(0, 1, 0);
    probarMcm(1, 0, 0);
    probarMcm(1, 1, 1);
    probarMcm(2, 2, 2);
    probarMcm(6, 6, 6);
    probarMcm(2, 3, 6);
    probarMcm(3, 2, 6);
    probarMcm(3, 12, 12);
    probarMcm(12, 3, 12);
    probarMcm(10, 15, 30);
    probarMcm(15, 10, 30);
    probarMcm(-10, 15, 30);
    probarMcm(10, -15, 30);
    probarMcm(-10, -15, 30);
    probarMcm(41273, 80758, 22369966);

    return 0;
}
