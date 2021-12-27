/*******************************************************************************
 * Curso de Programación 1. Práctica 3
 * Autores: Miguel Ángel Latre
 * Última revisión: 8 de octubre de 2021
 * Resumen: Fichero de interfaz de un módulo auxiliar «pruebas»
 *          que hace pruebas unitarias de las funciones del módulo
 *          «fechas».
 ******************************************************************************/

#pragma once

/*
 * Pre:  «valorEsperado» es el entero que, al ser escrito en base 10,
 *       tiene la forma «aaaammdd» que representa la fecha
 *       «dia»/«mes»/«agno», formada por los valores de los parámetros
 *       «dia», «mes» y «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «componer», invocada con los argumentos de entrada «dia»,
 *       «mes» y «agno», ha calculado el valor correcto «valorEsperado».
 *       En caso negativo, ha informado también acerca del valor
 *       incorrecto que calculó la función.
 */
void probarComponer(unsigned dia, unsigned mes, unsigned agno, 
                    unsigned valorEsperado);


/*
 * Pre:  «diaEsperado», «mesEsperado» y «agnoEsperado» son el día, mes y
 *       año representados por el entero «fecha» que, al ser escrito en
 *       base 10, tiene la forma «aaaammdd» donde los dígitos «aaaa»
 *       representan el año, los, dígitos «mm» el mes y los dígitos «dd»,
 *       el día.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «descomponer», invocada con el argumento de entrada
 *       «fecha», ha calculado los valores correctos de día, mes y año.
 *       En caso negativo, ha  informado también acerca de los valores
 *       incorrectos que calculó la función.
 */
void probarDescomponer(unsigned fecha, unsigned diaEsperado, 
                       unsigned mesEsperado, unsigned agnoEsperado);


/*
 * Pre:  «valorEsperado» es true si y solo si «fecha1» es anterior
 *       cronológicamente a «fecha2».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la función
 *       «esAnterior», invocada con los argumentos «fecha1» y «fecha2», ha
 *       devuelto el valor correcto «valorEsperado». En caso negativo, ha
 *       informado también acerca del valor incorrecto que devolvió la función.
 */
void probarEsAnterior(unsigned fecha1, unsigned fecha2, bool valorEsperado);


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
void probarDiasDelMes(unsigned mes, unsigned agno, unsigned valorEsperado);


/*
 * Pre:  agno > 1582 y «valorEsperado» es el número de días que tiene el
 *       año «agno».
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diasDelAgno», invocada con el argumento
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiasDelAgno(unsigned agno, unsigned valorEsperado);


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
                       unsigned valorEsperado);


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
                        unsigned agnoSigEsperado);
   
                        
/*
 * Pre:  1 ≤ dia ≤ 31, 1 ≤ mes ≤ 12 y agno >= 1900, la fecha formada por
 *       «dia/mes/agno» es una fecha válida del calendario gregoriano y
 *       «valorEsperado» codifica el día de la semana de la fecha
 *       representada por los valores de los parámetros «dia», «mes» y «agno», de
 *       acuerdo con la siguiente codificación: el 0 codifica el lunes, el 1
 *       codifica martes y así sucesivamente hasta el 6, que codifica el domingo.
 * Post: Ha escrito un mensaje en pantalla informando acerca de si la
 *       función «diaDeLaSemana», invocada con los argumentos «dia», «mes» y
 *       «agno», ha devuelto el valor correcto «valorEsperado». En caso
 *       negativo, ha informado también acerca del valor incorrecto
 *       devuelto por la función.
 */
void probarDiaDeLaSemana(unsigned dia, unsigned mes, unsigned agno,
                         unsigned valorEsperado);
