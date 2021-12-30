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
        if ( (i >=11 &&  i <= 14 ) || (i >= 19 && i <= 22) ) // Como en nuestro vector gasto, la componente 0 era la hora 1, tenemos que sumar 1.
        {
            coste += gasto.consElect[i] * tarifa.punta;
        } else if ((i >=9 &&  i <= 10 ) || (i >= 15 && i <= 18)) 
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
    return coste;
}