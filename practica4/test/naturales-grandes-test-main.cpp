/******************************************************************************\
 * Programación 1. Práctica 4
 * Autores: Miguel Ángel Latre
 * Ultima revisión: 31 de octubre de 2020
 * Resumen: Programa de pruebas del módulo «naturales-grandes» de la 4ª 
 *          práctica.
 * Nota: Para facilitar la escritura de este programa de pruebas, los números
 *       grandes se han expresado como cadenas de caracteres. Las funciones 
 *       «convertirAString» y «convertirDeString» del módulo 
 *       «naturales-grandes-test» convierten estas cadenas de caracteres a los
 *       vectores de enteros sin signo que se utilizan en el módulo
 *       «naturales-grandes».
\******************************************************************************/

#include <iostream>
#include "naturales-grandes-test.hpp"
using namespace std;


/* 
 * Programa que prueba las funciones de la biblioteca «naturales-grandes»
 */
int main() {
    probarCopiar("0");
    probarCopiar("1");
    probarCopiar("123");
    probarCopiar("123456789012345678901234567890123456789012345678901234567890");

    probarSonIguales("0", "0", true);
    probarSonIguales("0", "1", false);
    probarSonIguales("1", "0", false);
    probarSonIguales("4444", "4444", true);
    probarSonIguales("1444", "4444", false);
    probarSonIguales("4444", "1444", false);
    probarSonIguales("4144", "4444", false);
    probarSonIguales("4414", "4444", false);
    probarSonIguales("4441", "4444", false);
    probarSonIguales("1234567890", "1234567890", true);
    probarSonIguales("12345678901234567890", "1234567890", false);
    probarSonIguales("1234567890", "12345678901234567890", false);
    probarSonIguales("1234567890123456789012345678901234567890", 
                     "1234567890123456789012345678901234567890", true);
    probarSonIguales("123456789012345678901234567890123456789012345678901234567890", 
                     "1234567890123456789012345678901234567890", false);
    probarSonIguales("1234567890123456789012345678901234567890", 
                     "123456789012345678901234567890123456789012345678901234567890", false);

    probarNumCifras("0", 1);
    probarNumCifras("1", 1);
    probarNumCifras("9", 1);
    probarNumCifras("10", 2);
    probarNumCifras("99", 2);
    probarNumCifras("100", 3);
    probarNumCifras("123456789", 9);
    probarNumCifras("123456789012345678901234567890", 30);
    probarNumCifras("12345678901234567890123456789012345678901234567890", 50);

    probarConvertir(0, "0");
    probarConvertir(1, "1");
    probarConvertir(902, "902");
    probarConvertir(10015, "10015");
    probarConvertir(27043573, "27043573");
    probarConvertir(4294967295, "4294967295");

    // Elemento neutro
    probarSumar("0", "0", "0");
    probarSumar("132", "0", "132");
    probarSumar("0", "132", "132");
    probarSumar("0", "335", "335");
    probarSumar("335", "0", "335");
    // Sumas sin llevar
    probarSumar("802", "100", "902");
    probarSumar("100", "802", "902");
    probarSumar("802", "10", "812");
    probarSumar("10", "802", "812");
    // Con acarreo
    probarSumar("8", "8", "16");
    probarSumar("189", "21", "210");
    probarSumar("21", "189", "210");
    probarSumar("9999", "1", "10000");
    probarSumar("1", "9999", "10000");
    // De más de 20 dígitos (no representables como int ni como long long)
    probarSumar("123412345678901234567890", "10", "123412345678901234567900");
    probarSumar("10", "123412345678901234567890", "123412345678901234567900");
    probarSumar("999999999999999999999999", "1", "1000000000000000000000000");
    probarSumar("1", "999999999999999999999999", "1000000000000000000000000");

    probarValor("0", 0);
    probarValor("7", 7);
    probarValor("18", 18);
    probarValor("903", 903);
    probarValor("100670", 100670);
    probarValor("123456789", 123456789);

    probarCalcularImagen("0", "0");
    probarCalcularImagen("000", "0");
    probarCalcularImagen("1", "1");
    probarCalcularImagen("18", "81");
    probarCalcularImagen("903", "309");
    probarCalcularImagen("123456789", "987654321");
    probarCalcularImagen("1030507090", "907050301");
    probarCalcularImagen("123412345678901234567890", "98765432109876543214321");

    probarEsCapicua("0", true);
    probarEsCapicua("1", true);
    probarEsCapicua("10", false);
    probarEsCapicua("11", true);
    probarEsCapicua("100", false);
    probarEsCapicua("101", true);
    probarEsCapicua("91718", false);
    probarEsCapicua("91719", true);
    probarEsCapicua("12341234567890123456789", false);
    probarEsCapicua("123412345678909876543214321", true);

    return 0;
}
