/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros) y trabajo obligatorio 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Última revisión: 2 de Enero de 2022
 * Resumen: Fichero de implementación «tarifas-comerciales.cpp» del módulo «tarifas-comerciales».
\******************************************************************************/
#include <string>
#include "gasto-diario.hpp"
#include "tarifas-comerciales.hpp"
#pragma once
using namespace std;

/*
 * Pre:  ---
 * Post: Devuelve el importe en euros del coste de la energía eléctrica
 *       reflejados por los datos del registro «gasto» suponiendo que se han
 *       aplicado los costes especificados por la tarifa del parámetro «tarifa».
 */
double costeDiarioTarifaPlanaTramos(const GastoDiario& gasto, const TarifaPlanaTramos tarifa){
    double coste = 0;
    for (unsigned i = 0; i < NUM_HORAS; i++)
    {
        if ( (i >=10 &&  i <= 13 ) || (i >= 18 && i <= 21) )
        {
            coste += gasto.consElect[i] * tarifa.punta;
        } else if ((i >=8 &&  i <= 9 ) || (i >= 14 && i <= 17) || (i >= 20 && i <= 23)) 
        {
            coste += gasto.consElect[i] * tarifa.llano;
        } else {
            coste += gasto.consElect[i] * tarifa.valle;
        }
    }
    return coste;
}


/*
 * Pre:  ---
 * Post: Devuelve el importe en euros del coste de la energía eléctrica
 *       reflejados por los datos de las «numRegs» primeras componentes del
 *       vector «regDiario» suponiendo que se han aplicado en cada uno de los
 *       días de dichas componentes los costes especificados por la tarifa del
 *       parámetro «tarifa».
 */
double costeTarifaPlanaTramos(const GastoDiario regDiario[], const unsigned numRegs, const TarifaPlanaTramos tarifa){
    double coste = 0;
    for (unsigned i = 0; i < numRegs; i++)
    {
        coste += costeDiarioTarifaPlanaTramos(regDiario[i],tarifa);
    }
    return coste * 1000;
}