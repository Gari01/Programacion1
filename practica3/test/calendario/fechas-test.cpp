/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 22 de octubre de 2018
 * Resumen: Fichero de implementación de un módulo auxiliar «pruebas»
 *          que hace pruebas unitarias de las funciones del módulo
 *          «fechas».
 *          Para escribir estas funciones, solo se han utilizado
 *          conceptos de C++ que se han visto en la asignatura (es por
 *          ello que hay mucho código repetido, ya que las estructuras
 *          de las funciones se repiten).
 ******************************************************************************/

#include <iostream>
#include "testing-prog1.hpp"
#include "fechas.hpp"
using namespace std;


/*
 * Pre:  «valorEsperado» es el entero que, al ser escrito en base 10, tiene
 *       la forma aaaammdd que representa la fecha «dia»/«mes»/«agno» donde los
 *       dígitos  aaaa representan el año, los dígitos mm el mes y los
 *       digitos dd el día de la fecha dia/mes/anyo.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «componer», invocada con los argumentos de entrada «dia», «mes» y
 *       «agno», ha calculado el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto que calculó
 *       la función.
 */
void probarComponer(unsigned dia, unsigned mes, unsigned agno, 
                    unsigned valorEsperado) {
    cout << "Prueba componer(" << dia << ", " << mes << ", " << agno
         << ", int&) ";
    unsigned valorCalculado;
    componer(dia, mes, agno, valorCalculado);
    escribirResultadoPrueba(valorEsperado, valorCalculado);
}


/*
 * Pre:  «diaEsperado», «mesEsperado» y «agnoEsperado» son el día, mes y año
 *       representados por el entero «fecha» que, al ser escrito en base 10,
 *       tiene la forma aaaammdd donde los dígitos aaaa representan el año, los
 *       dígitos mm el mes y los  digitos dd el día.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «descomponer», invocada con el argumento de entrada «fecha», ha
 *       calculado los valores correctos de día, mes y año. En caso negativo, ha
 *       informado también acerca de los valores incorrectos que calculó la
 *       función.
 */
void probarDescomponer(unsigned fecha, 
            unsigned diaEsperado, unsigned mesEsperado, unsigned agnoEsperado) {
    cout << "Prueba descomponer(" << fecha << ", int&, int&, int&) ";
    unsigned diaCalculado, mesCalculado, agnoCalculado;
    descomponer(fecha, diaCalculado, mesCalculado, agnoCalculado);
    if (diaCalculado == diaEsperado && mesCalculado == mesEsperado &&
        agnoCalculado == agnoEsperado) {
        cout << "correcta" << endl;
    }
    else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber calculado "
             << "dia=" << diaEsperado << ", mes=" << mesEsperado << " y anyo="
             << agnoEsperado << endl
             << "   pero ha calculado "
             << "dia=" << diaCalculado << ", mes=" << mesCalculado << " y anyo="
             << agnoCalculado << endl;
    }
}


/*
 * Pre:  1 ≤ mes ≤ 12, agno > 1582 y «valorEsperado» es el número de días
 *       del mes correspondiente al parámetro «mes» del año
 *       correspondiente al parámetro «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelMes», invocada con los argumentos «mes» y «agno»,
 *       ha devuelto el valor correcto «valorEsperado». En caso negativo,
 *       ha informado también acerca del valor incorrecto devuelto por
 *       la función.
 */
void probarDiasDelMes(unsigned mes, unsigned agno, unsigned valorEsperado) {
    cout << "Prueba diasDelMes(" << mes << ", " << agno << ") ";
    unsigned valorDevuelto = diasDelMes(mes, agno);
    escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


/*
 * Pre:  agno > 1582 y «valorEsperado» es el número de días que tiene el
 *       año «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelAgno», invocada con el argumento
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiasDelAgno(unsigned agno, unsigned valorEsperado) {
    cout << "Prueba diasDelAgno(" << agno << ") ";
    unsigned valorDevuelto = diasDelAgno(agno);
    escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno > 1582, la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano y
 *       «valorEsperado» es el número de día del año de esa fecha.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diaEnElAgno», invocada con los argumentos «dia», «mes» y
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiaEnElAgno(unsigned dia, unsigned mes, unsigned agno, 
                       unsigned valorEsperado) {
    cout << "Prueba diaEnElAgno(" << dia << ", " << mes << ", " << agno
         << ") ";
    unsigned valorDevuelto = diaEnElAgno(dia, mes, agno);
    escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


/*
 * Pre:  «valorEsperado» es true si y solo si «fecha1» es anterior
 *       cronológicamente a «fecha2».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esAnterior», invocada con los argumentos «fecha1» y «fecha2», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarEsAnterior(unsigned fecha1, unsigned fecha2, bool valorEsperado) {
    cout << "Prueba esAnterior(" << fecha1 << ", " << fecha2 << ") ";
    bool valorDevuelto = esAnterior(fecha1, fecha2);
    escribirResultadoPrueba(valorEsperado, valorDevuelto);
}


/*
 * Pre:  La fecha formada por «diaSigEsperado»/«mesSigEsperado»/«agnoSigEsperado»
 *       representa el día siguiente a la fecha formada por «dia»/«mes»/«agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «diaSiguiente», invocada con los argumentos «dia», «mes» y «agno», ha
 *       obtenido los valores correctos correspondientes a la fecha siguiente 
 *       («diaSigEsperado», «mesSigEsperado» y «agnoSigEsperado»). En caso
 *       negativo, ha informado también acerca del valor incorrecto que devolvió
 *       la función.
 */
void probarDiaSiguiente(unsigned dia, unsigned mes, unsigned agno,
        unsigned diaSigEsperado, unsigned mesSigEsperado,
        unsigned agnoSigEsperado) {
    cout << "Prueba diaSiguiente(" << dia << ", " << mes << ", " << agno << ") ";
    diaSiguiente(dia, mes, agno);
    if (dia == diaSigEsperado && mes == mesSigEsperado 
            && agno == agnoSigEsperado) {
        cout << "correcta." << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber obtenido dia=" << diaSigEsperado << ", mes=" 
             << mesSigEsperado << ", agno=" << agnoSigEsperado << ',' << endl;
        cout << "         pero ha obtenido dia=" << dia << ", mes=" << mes 
             << ", agno=" << agno << '.' << endl;
    }
}


/*
 * Pre:  ---
 * Post: Ha escrito el valor entero «diaSemana» en la pantalla. Además, si está
 *       comprendido entre 0 y 6, inclusive, ha escrito en letra y entre
 *       paréntesis el día de la semana de que se trata, de
 *       acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo
 */
void escribirDiaSemana(unsigned diaSemana) {
    cout << diaSemana;
    if (diaSemana == 0) {
        cout << " (lunes)";
    }
    else if (diaSemana == 1) {
        cout << " (martes)";
    }
    else if (diaSemana == 2) {
        cout << " (miércoles)";
    }
    else if (diaSemana == 3) {
        cout << " (jueves)";
    }
    else if (diaSemana == 4) {
        cout << " (viernes)";
    }
    else if (diaSemana == 5) {
        cout << " (sábado)";
    }
    else if (diaSemana == 6) {
        cout << " (domingo)";
    }
    else {
        cout << diaSemana << " (no se corresponde con ningún código válido [0-6])";
    }
}


/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno >= 1900, la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano y
 *       «valorEsperado» codifica el día de la semana de la fecha
 *       representada por los valores de los parámetros «dia», «mes» y «agno»,
 *       de acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diaDeLaSemana», invocada con los argumentos «dia», «mes» y
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiaDeLaSemana(unsigned dia, unsigned mes, unsigned agno,
                         unsigned valorEsperado) {
    cout << "Prueba diaDeLaSemana(" << dia << ", " << mes << ", " << agno << ") ";
    unsigned valorDevuelto = diaDeLaSemana(dia, mes, agno);
    if (valorDevuelto == valorEsperado) {
        cout << "correcta." << endl;
    } else {
        cout << "incorrecta:" << endl;
        cout << "   debería haber devuelto ";
        escribirDiaSemana(valorEsperado);
        cout << ", pero ha devuelto ";
        escribirDiaSemana(valorDevuelto);
        cout << '.' << endl;
    }
}
