/******************************************************************************\
 * Programación 1. Práctica 5
 * Autor: Gari Arellano Zubía
 * Ultima revisión: 06/11/2021
 * Resumen: Fichero de implementación del módulo principal del programa que 
 *          trabaja con números complejos.
 * Nota: El código de este programa no está repartido en varios módulos, por lo
 *       que se puede utilizar la extensión Code Runner de VSC para ejecutarlo.
 *       No obstante, se ha configurado el fichero «Makefile» para poder 
 *       compilarlo y se han definido tareas de VSC para compilarlo, ejecutarlo 
 *       y depurarlo.
 *       Para compilarlo, se puede ejecutar el comando
 *           make complejos
 *       o, en Windows,
 *           mingw32-make complejos
 *       o ejecutar la tarea "Compilar «complejos»" de VSC
 * 
 *       Para ejecutarlo, una vez compilado, se puede ejecutar el comando
 *           bin/complejos
 *       o, en Windows,
 *           bin\complejos.exe
 *       o ejecutar la tarea "Ejecutar «complejos»" de VSC
 *       o compilarlo y ejecutarlo con la extensión Code Runner (Ctrl+Alt+N).
\******************************************************************************/

#include <iostream>
#include <cstdlib> 
#include <iomanip>  
#include <cmath> 

using namespace std;
const int DIM = 5;
// Creo el registro para los numeros complejos.
struct complejo
{
    double ParteReal;
    double ParteCompleja;
};
/*
Pre: 
Post: Imprime por pantalla un mensaje solicitando que se introduzcan dos numeros, que se utilizaran como limites de un intervalo.
*/
void PedirDatos(double& extremo1, double& extremo2){
    cout << "Introduce los límites del intervalo (x < y): ";
    cin >> extremo1 >> extremo2;
}
/*
Pre: El extremo1 < extremo2
Post: Asigna al vector "vectorComplejos", valores de numeros complejos aleatorios, dentro del intervalo anteriormente introducido por el usuario.
*/
void crearComplejo(complejo vectorComplejos[DIM], const double extremo1, const double extremo2){
    for (unsigned i = 0; i < DIM; i++)
    {
        vectorComplejos[i].ParteReal = extremo1 + (double)rand()/RAND_MAX*(extremo2 - extremo1);
        vectorComplejos[i].ParteCompleja = extremo1 + (double)rand()/RAND_MAX*(extremo2 - extremo1);
    }
}
/*
Pre: 
Post: Devuelve un double con el modulo del numero complejo que le pasamos a la funcion.
*/
double calculoModulo(complejo numComplejo){
    return sqrt(pow(numComplejo.ParteReal,2) + pow(numComplejo.ParteCompleja,2));
}
/*
Pre: 
Post: Devuelve, un dato tipo unsigned, que hace referencia a la posicion en el vectorComplejos del complejo con mayor modulo.
*/
unsigned MaximoModulo(complejo vectorComplejos[DIM]){
    unsigned MaxModulo = 0;
    for (unsigned i = 1; i < DIM; i++)
    {
        if(calculoModulo(vectorComplejos[i]) > calculoModulo(vectorComplejos[MaxModulo]) )
        {
            MaxModulo = i;
        }
    }
    return MaxModulo;
}
/*
Pre: 
Post: Devuelve, un dato tipo unsigned, que hace referencia a la posicion en el vectorComplejos del complejo con menor modulo.
*/
unsigned MinModulo(complejo vectorComplejos[DIM]){
    unsigned MinModulo = 0;
    for (unsigned i = 1; i < DIM; i++)
    {
        if(calculoModulo(vectorComplejos[i]) < calculoModulo(vectorComplejos[MinModulo]) )
        {
            MinModulo = i;
        }
    }
    return MinModulo;
}
/*
Pre: 
Post: Devuelve un dato de tipo complejo, el cual es la suma de todos los complejos que contiene el "vectorComplejos"
*/
complejo suma(complejo vectorComplejos[DIM]){
    complejo suma;
    for (unsigned i = 0; i < DIM; i++)
    {
        suma.ParteReal = suma.ParteReal + vectorComplejos[i].ParteReal; 
        suma.ParteCompleja = suma.ParteCompleja + vectorComplejos[i].ParteCompleja;
    }
    return suma;
}
/*
Pre: 
Post: Imprime por pantalla un mensaje solicitando que se introduzcan dos numeros, que se utilizaran como limites de un intervalo.
*/
void pintarComplejo(complejo NumComplejo){
    cout << NumComplejo.ParteReal; 
    if (NumComplejo.ParteCompleja >= 0)
    {
        cout << "+" ;
    }
    cout << NumComplejo.ParteCompleja << "i";
}
/*
Pre: 
Post: Programa que nos permite generar 5 numeros complejos "random" a partir de dos intervalos, introducidos por el usuario,
* tambien calcula quien es el numero complejo con mayor y menos modulo de los generados y una suma de todos los numeros complejos generados.
*/
int main() {
    double extremo1,extremo2;
    complejo vectorComplejos[DIM];
    do
    {
        PedirDatos(extremo1,extremo2);
    } while (extremo1 >= extremo2);
    crearComplejo(vectorComplejos,extremo1,extremo2);
    cout << fixed << setprecision(2);
    cout << "Números complejos generados:" << endl;
    for (unsigned i = 0; i < DIM; i++)
    {
        pintarComplejo(vectorComplejos[i]);
        if (i < 4)
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Números complejos de mayor y menor módulo, respectivamente:" << endl;
    pintarComplejo(vectorComplejos[MaximoModulo(vectorComplejos)]);
    cout << " y ";
    pintarComplejo(vectorComplejos[MinModulo(vectorComplejos)]);
    cout << endl;
    cout << "Suma:" << endl;
    pintarComplejo(suma(vectorComplejos));
    return 0;
}
