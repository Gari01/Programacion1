/******************************************************************************\
 * Programación 1. Práctica 5
 * Autor: ¡¡¡PON AQUÍ TU NOMBRE!!!
 * Ultima revisión: ¡¡¡¡!!!!
 * Resumen: Fichero de implementación del módulo principal del programa del 
 *          Juego de la vida en la 5.ª práctica.
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       No obstante, se ha configurado el fichero «Makefile» para poder 
 *       compilarlo y se han definido tareas de VSC para compilarlo, ejecutarlo 
 *       y depurarlo.
 *       Para compilarlo, se puede ejecutar el comando
 *           make juego-vida
 *       o, en Windows,
 *           mingw32-make juego-vida
 *       o ejecutar la tarea "Compilar «juego-vida»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/juego-vida
 *       o, en Windows,
 *           bin\juego-vida.exe
 *       o ejecutar la tarea "Ejecutar «juego-vida»" de VSC.
\******************************************************************************/

#include <iostream>
using namespace std;

const unsigned MAX_FILAS = 50;
const unsigned MAX_COLUMNAS = 50;

/*
 * Pre:  ---
 * Post: Borra la parte visible del terminal y mueve el cursor a la primera
 *       fila y la primera columna, de forma que la siguiente instrucción de 
 *       escritura en pantalla escriba desde el inicio de la parte visible del
 *       terminal.
 */
void borrarPantalla() {
    cout << "\033[2J";
}

/*
 * Pre:  ---
 * Post: Sube el cursor de escritura del terminal «lineas» líneas, sin borrar
 *       el contenido que ya esté escrito en el terminal.
 */
void subirCursor(const unsigned lineas) {
    cout << "\033[" << lineas << "A";
}

int main() {
    return 0;
}
