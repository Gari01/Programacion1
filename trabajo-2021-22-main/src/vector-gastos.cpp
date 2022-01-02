/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros) y trabajo obligatorio 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Última revisión: 28 de diciembre de 2021
 * Resumen: Fichero de implementación «vector-gastos.cpp» del módulo «vector-gastos».
\******************************************************************************/

#include "fecha.hpp"
#include <iostream>
#include "gasto-diario.hpp"
#include "vector-gastos.hpp"
using namespace std;

/*
 * Pre:  Las primeras «numRegs» componentes del vector «regsDiarios» almacenan
 *       datos de precios horarios de energía eléctrica.
 * Post: Asigna al parámetro «dia» el día en el que se registró el menor precio
 *       diario promedio de entre las primeras «numRegs» componentes del vector
 *       «regsDiarios» y al parámetro «precioMaximo», el valor de ese precio
 *       promedio diario mínimo.
 */
void diaMasBarato(const GastoDiario regsDiarios[], const unsigned numRegs, Fecha& dia, double& precioMedioMinimo){
    precioMedioMinimo = costeMedio(regsDiarios[0]);
    dia = regsDiarios[0].fecha;
    for (unsigned i = 1; i < numRegs; i++)
    {
        if (precioMedioMinimo > costeMedio(regsDiarios[i]))
        {
            precioMedioMinimo = costeMedio(regsDiarios[i]);
            dia = regsDiarios[i].fecha; // Igualo los dos struct, para obtener la fecha.
        }
    }
}

/*
 * Pre:  Las primeras «numRegs» componentes del vector «regsDiarios» almacenan
 *       datos de precios horarios de energía eléctrica.
 * Post: Asigna al parámetro «dia» el día en el que se registró el mayor precio
 *       horario de entre las primeras «numRegs» componentes del vector
 *       «regsDiarios»; al parámetro «hora», la hora de ese día en la que se
 *       registró ese mayor precio horario y al parámetro «precioMaximo», el
 *       valor de ese precio máximo.
 */
void horaMasCara(const GastoDiario regsDiarios[], const unsigned numRegs, Fecha& dia, unsigned& hora, double& precioMaximo){
    hora = horaMasCara(regsDiarios[0]); // Inicializamos la variable fuera del bucle, para que no tenga que estar inicializando una nueva variable en memoria por cada iteración bucle.
    double precioActual;
    unsigned horaActual;
    precioMaximo = regsDiarios[0].precioDia[hora];
    dia = regsDiarios[0].fecha;
    for (unsigned i = 1; i < numRegs; i++)
    {
        horaActual = horaMasCara(regsDiarios[i]); // Guardamos el indice en una variable, para llamar a la función una sola vez por cada iteracion, en vez de dos.
        precioActual = regsDiarios[i].precioDia[horaActual];
        if (precioMaximo < precioActual)
        {
            precioMaximo = precioActual;
            dia = regsDiarios[i].fecha;
            hora = horaActual;
        }
    }
}

/*
 * Pre:  Las primeras «numRegs» componentes del vector «regsDiarios» almacenan
 *       datos de precios y consumo horarios de energía eléctrica.
 * Post: Devuelve el coste en euros de la energía eléctrica consumida según los
 *       datos de las primeras «numRegs» componentes del vector «regsDiarios».
 */
double costeTerminoVariable(const GastoDiario regsDiarios[], const unsigned numRegs){
    double coste = costeDiario(regsDiarios[0]);
    for (unsigned i = 1; i < numRegs; i++)
    {
        coste += costeDiario(regsDiarios[i]);
    }
    return coste*1000;
}

/*
 * Pre:  Las primeras «numRegs» componentes del vector «regsDiarios» almacenan
 *       datos de precios y consumo horarios de energía eléctrica.
 * Post: Devuelve el coste en euros del coste de la energía eléctrica consumida 
 *       según los datos de las primeras «numRegs» componentes del vector
 *       «regsDiarios», suponiendo que TODO el consumo de cada uno de los días
 *       almacenados en las componentes de «regsDiarios» se ha producido
 *       precisamente en la hora más barata de ese día.
 */
double costeMinimoPosible(const GastoDiario regsDiarios[], const unsigned numRegs){
    double coste = costeDiarioMinimo(regsDiarios[0]);
    for (unsigned i = 1; i < numRegs; i++)
    {
        coste += costeDiarioMinimo(regsDiarios[i]);
    }
    return coste*1000;
}