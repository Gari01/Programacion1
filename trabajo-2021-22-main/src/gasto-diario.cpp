/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros) y trabajo obligatorio 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Última revisión: 27 de diciembre de 2021
 * Resumen: Fichero de implementación «gasto-diario.cpp» del módulo «gasto-diario».
\******************************************************************************/

#include <iostream>
#include "gasto-diario.hpp"
using namespace std;

/*
 * Pre:  ---
 * Post: Devuelve la hora en la que el precio de la electricidad según los datos
 *       de precios horarios del registro «gasto» fue más cara.
 */
unsigned horaMasCara(const GastoDiario& gasto){
    unsigned indice = 0;
    for (unsigned i = 1; i < NUM_HORAS; i++) 
    {
        if (gasto.precioDia[indice] < gasto.precioDia[i])
        {
            indice = i;
        }
    }
    return indice; 
}

/*unsigned horaMasCara(const GastoDiario& gasto){
    unsigned maxPrecio;
    unsigned indice = 0;
    maxPrecio = gasto.precioDia[indice];
    for (unsigned i = 1; i < NUM_HORAS; i++) // En la componente 0, esta la hora 1, por lo tanto en la componente 23, la hora 24
    {
        if (maxPrecio < gasto.precioDia[i])
        {
            maxPrecio = gasto.precioDia[i];
            indice = i;
        }
    }
    return indice; // Como ya hemos especificado antes, hay que sumar uno al indice.
}*/

/*
 * Pre:  ---
 * Post: Devuelve el precio medio de la electricidad según los datos de precios
 *       horarios del registro «gasto».
 */
double costeMedio(const GastoDiario& gasto){
    double acumPrecio = gasto.precioDia[0];
    for (unsigned i = 1; i < NUM_HORAS; i++) 
    {
        acumPrecio += gasto.precioDia[i];
    }
    return acumPrecio/NUM_HORAS;
}


/*
 * Pre:  ---
 * Post: Devuelve el importe en euros del coste de la energía eléctrica
 *       reflejados por los datos del registro «gasto».
 */
double costeDiario(const GastoDiario& gasto){
    double coste = gasto.precioDia[0] * gasto.consElect[0];
    for (unsigned i = 1; i < NUM_HORAS; i++)
    {
        coste += gasto.precioDia[i] * gasto.consElect[i];
    }
    return coste;
}


/*
 * Pre:  ---
 * Post: Devuelve el importe en euros del coste de la energía eléctrica
 *       reflejados por los datos del registro «gasto» suponiendo que todo el 
 *       consumo eléctrico reflejado en el registro «gasto» hubiera tenido lugar
 *       en la hora con el precio más barato del registro «gasto».
 */
double costeDiarioMinimo(const GastoDiario& gasto){
    double costeMin = 0; // Inicializamos la variable, para dar una vuelta menos en el bucle.
    unsigned indice = 0;
    for (unsigned i = 1; i < NUM_HORAS; i++) // Localizamos cual es el indice correpondiente a la hora mas barata.
    {
        if (gasto.precioDia[indice] > gasto.precioDia[i])
        {
            indice = i;
        }
    }
    for (unsigned i = 0; i < NUM_HORAS; i++)
    {
        costeMin += gasto.consElect[i] * gasto.precioDia[indice]; // Reutilizamos la variable costeMin, ya que su valor anterior no nos interesa.
    }
    return costeMin;
}
