/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Módulo principal de un programa que hace pruebas unitarias de
 *          las funciones del módulo «fechas».
 * Nota: Leer el fichero README.md, que contiene instrucciones para su 
 *       compilación y ejecución.
 ******************************************************************************/

 #include <iostream>
 #include "fechas-test.hpp"
 using namespace std;


/*
 * Programa que realiza pruebas unitarias de las funciones del módulo de
 * biblioteca «fechas». Por cada prueba, indica los parámetros utilizados y si
 * el resultado es correcto o no. Además, en los casos negativos, indica las
 * salidas producidas por la función y las que debería haber producido.
 */
int main() {
    probarComponer(31, 10, 2016, 20161031);
    probarComponer(1, 11, 2016, 20161101);
    probarComponer(19, 9, 2016, 20160919);
    probarComponer(1, 2, 2017, 20170201);

    probarDescomponer(20161031, 31, 10, 2016);
    probarDescomponer(20161101, 1, 11, 2016);
    probarDescomponer(20160919, 19, 9, 2016);
    probarDescomponer(20170201, 1, 2, 2017);

    probarEsAnterior(20161031, 20161031, false);
    probarEsAnterior(20161030, 20161031, true);
    probarEsAnterior(20161031, 20161030, false);
    probarEsAnterior(20161130, 20161031, false);
    probarEsAnterior(20161031, 20161130, true);
    probarEsAnterior(20161130, 20171031, true);
    probarEsAnterior(20171031, 20161130, false);
    
    probarDiaSiguiente(30, 10, 2016,  31, 10, 2016);
    probarDiaSiguiente(31, 10, 2016,   1, 11, 2016);
    probarDiaSiguiente(30, 11, 2016,   1, 12, 2016);
    probarDiaSiguiente(31, 12, 2016,   1,  1, 2017);
    probarDiaSiguiente(28,  2, 2017,   1,  3, 2017);
    probarDiaSiguiente(28,  2, 2016,  29,  2, 2016);
    probarDiaSiguiente(28,  2, 2100,   1,  3, 2100);
    probarDiaSiguiente(28,  2, 2000,  29,  2, 2000);

    probarDiasDelMes( 1, 2018, 31);
    probarDiasDelMes( 2, 2018, 28);
    probarDiasDelMes( 2, 2020, 29);
    probarDiasDelMes( 2, 2100, 28);
    probarDiasDelMes( 2, 2400, 29);
    probarDiasDelMes( 3, 2018, 31);
    probarDiasDelMes( 4, 2018, 30);
    probarDiasDelMes( 5, 2018, 31);
    probarDiasDelMes( 6, 2018, 30);
    probarDiasDelMes( 7, 2018, 31);
    probarDiasDelMes( 8, 2018, 31);
    probarDiasDelMes( 9, 2018, 30);
    probarDiasDelMes(10, 2018, 31);
    probarDiasDelMes(11, 2018, 30);
    probarDiasDelMes(12, 2018, 31);

    probarDiasDelAgno(2019, 365);
    probarDiasDelAgno(2024, 366);
    probarDiasDelAgno(1900, 365);
    probarDiasDelAgno(2000, 366);

    probarDiaEnElAgno( 1,  1, 2019,  1);
    probarDiaEnElAgno( 2,  1, 2019,  2);
    probarDiaEnElAgno(31,  1, 2019, 31);
    probarDiaEnElAgno( 1,  2, 2019, 32);
    probarDiaEnElAgno(28,  2, 2019, 59);
    probarDiaEnElAgno( 1,  3, 2019, 60);
    probarDiaEnElAgno(31, 12, 2019, 365);
    probarDiaEnElAgno(31, 12, 2020, 366);
    
    const unsigned LUNES     = 0;
    const unsigned MARTES    = 1;
    const unsigned MIERCOLES = 2;
    const unsigned JUEVES    = 3;
    const unsigned VIERNES   = 4;
    const unsigned SABADO    = 5;
    const unsigned DOMINGO   = 6;
    
    probarDiaDeLaSemana( 1,  1, 1900, LUNES);
    probarDiaDeLaSemana( 2,  1, 1900, MARTES);
    probarDiaDeLaSemana( 7,  1, 1900, DOMINGO);
    probarDiaDeLaSemana( 8,  1, 1900, LUNES);
    probarDiaDeLaSemana(31,  1, 1900, MIERCOLES);
    probarDiaDeLaSemana( 1,  2, 1900, JUEVES);
    probarDiaDeLaSemana(28,  2, 1900, MIERCOLES);
    probarDiaDeLaSemana( 1,  3, 1900, JUEVES);
    probarDiaDeLaSemana(30,  4, 1900, LUNES);
    probarDiaDeLaSemana( 1,  5, 1900, MARTES);
    probarDiaDeLaSemana(31, 12, 1900, LUNES);
    probarDiaDeLaSemana( 1,  1, 1901, MARTES);
    probarDiaDeLaSemana(28,  2, 1901, JUEVES);
    probarDiaDeLaSemana( 1,  3, 1901, VIERNES);
    probarDiaDeLaSemana(29,  2, 1904, LUNES);
    probarDiaDeLaSemana( 1,  3, 1904, MARTES);
    probarDiaDeLaSemana(29,  2, 2000, MARTES);
    probarDiaDeLaSemana( 1,  3, 2000, MIERCOLES);
    
    probarDiaDeLaSemana(27, 10, 2019, DOMINGO);
    probarDiaDeLaSemana(28, 10, 2019, LUNES);
    probarDiaDeLaSemana(29, 10, 2019, MARTES);
    probarDiaDeLaSemana(30, 10, 2019, MIERCOLES);
    probarDiaDeLaSemana(31, 10, 2019, JUEVES);
    probarDiaDeLaSemana( 1, 11, 2019, VIERNES);
    probarDiaDeLaSemana( 2, 11, 2019, SABADO);
    probarDiaDeLaSemana( 3, 11, 2019, DOMINGO);
    probarDiaDeLaSemana( 4, 11, 2019, LUNES);

    return 0;
}
