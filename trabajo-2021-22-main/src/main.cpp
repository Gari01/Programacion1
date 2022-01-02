/******************************************************************************\
 * Programación 1. Trabajo obligatorio curso 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Ultima revisión: 2 de Enero de 2022
 * Resumen: ¡¡¡!!!
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make all
 *       o, en Windows,
 *           mingw32-make all
 *       o ejecutar la tarea "Compilar «electricidad»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/electricidad
 *       o, en Windows,
 *           bin\electricidad.exe
 *       o ejecutar la tarea "Ejecutar «electricidad»" de VSC.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "gasto-diario.hpp"
#include "fichs-electricos.hpp"
#include "vector-gastos.hpp"
#include "tarifas-comerciales.hpp"
#include "fecha.hpp"
using namespace std;


/*
 * Pre:  «f» es «cout» o un flujo de la clase «ofstream» asociado con un fichero
 *       externo abierto para escritura. Las «numRegs» primeras componentes
 *       del vector «regDiarios» contienen datos diarios de precios y consumo
 *       eléctricos de un determinado cliente de nombre «nombreCliente» entre
 *       los meses «mesInicial» y «mesFinal».
 * Post: Ha escrito en el flujo «f» el informe sobre consumo eléctrico indicado
 *       en el enunciado de este trabajo.
 */
void escribirInforme(ostream& f, const GastoDiario regDiarios[], const unsigned numRegs, const string nombreCliente, const unsigned mesInicial, 
                    const unsigned mesFinal) {
    f << endl << endl << "INFORME DEL CLIENTE " << nombreCliente << " ENTRE LOS MESES " << mesInicial << " Y " << mesFinal << " DE " << AGNO_ACTUAL << endl;
    f << "-------------------------------------------------------------------------------------" << endl;
    double precio;
    Fecha fecha;
    diaMasBarato(regDiarios, numRegs, fecha, precio);
    f << "El día completo más barato fue el " << fecha.dia << "-" << fecha.mes << "-" << AGNO_ACTUAL << ". Precio medio: " << precio << " €/kWh"<< endl;
    unsigned hora;
    horaMasCara(regDiarios, numRegs, fecha, hora, precio);
    f << "La hora más cara tuvo lugar el " << fecha.dia << "-" << fecha.mes << "-" << AGNO_ACTUAL << " a las " << hora << ":00. Precio: " << precio << " €/kWh"; 
    f << endl << endl;
    f << "El importe del consumo eléctrico en el periodo considerado ha sido de " << costeTerminoVariable(regDiarios,numRegs) << "€." << endl;
    f << "El importe mínimo concentrando todo el consumo diario en la hora más barata " << endl << "habría sido de "; 
    f << costeMinimoPosible(regDiarios,numRegs) << "€ ";
    f << "(un "<< 100 - (costeMinimoPosible(regDiarios,numRegs) * 100) / costeTerminoVariable(regDiarios,numRegs)<< " % menor)" << endl;
    f << "COSTE CON TARIFAS COMERCIALES" << endl;
    f << "Coste "<<"Nombre de la tarifa" << endl;
    f << "--------------------------------------------" << endl;
    for (unsigned i = 0; i < NUM_TARIFAS_COMERCIALES; i++)
    {
       f << costeTarifaPlanaTramos(regDiarios,numRegs,TARIFAS_COMERCIALES[i]) << " €     "<< TARIFAS_COMERCIALES[i].nombre << endl; 
    }


}

void pedirDatos(string& usuario, unsigned& mesIni, unsigned& mesFinal){
    cout << "Escriba el nombre del usuario: ";
    cin >> usuario;
    do
    {
        cout << endl << "Escriba el mes inicial y el final: ";
        cin >> mesIni >> mesFinal;
        if (mesIni < 1 || mesIni > 11)
        {
            cout << "El mes inicial tiene que estar entre 1 y 11." << endl;
        }
        if (mesFinal < 1 || mesFinal > 11)
        {
            cout << "El mes final tiene que estar entre 1 y 11." << endl;
        }
        if (mesIni >> mesFinal)
        {
            cout << "El mes inicial tiene que ser menor o igual que el mes final." << endl;
        }
    } while (mesIni > mesFinal || mesIni < 1 || mesIni > 11 || mesFinal < 1 || mesFinal > 11);
}

bool pedirFich(string& nombreFich){
    cout << "Escriba el nombre del fichero del informe" << endl;
    cout << "(presione solo ENTRAR para escribirlo en la pantalla): ";
    char enter;
    cin.ignore();
    cin.get(enter);
    if (enter != '\n')
    {
        cin >> nombreFich;
        nombreFich = enter+nombreFich;
        return true;
    }
    return false;
}

void escribirEnPantalla (const unsigned& mesIni, const unsigned& mesFinal, const string& usuario, GastoDiario regsDiarios[MAX_DIAS], unsigned numregs){
    cout << endl << endl << "INFORME DEL CLIENTE " << usuario << " ENTRE LOS MESES " << mesIni << " Y " << mesFinal << " DE " << AGNO_ACTUAL << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    double precio;
    Fecha fecha;
    diaMasBarato(regsDiarios, numregs, fecha, precio);
    cout << "El día completo más barato fue el " << fecha.dia << "-" << fecha.mes << "-" << AGNO_ACTUAL << ". Precio medio: " << precio << " €/kWh"<< endl;
    unsigned hora;
    horaMasCara(regsDiarios, numregs, fecha, hora, precio);
    cout << "La hora más cara tuvo lugar el " << fecha.dia << "-" << fecha.mes << "-" << AGNO_ACTUAL << " a las " << hora << ":00. Precio: " << precio << " €/kWh"; 
    cout << endl << endl;
    cout << "El importe del consumo eléctrico en el periodo considerado ha sido de " << costeTerminoVariable(regsDiarios,numregs) << "€." << endl;
    cout << "El importe mínimo concentrando todo el consumo diario en la hora más barata " << endl << "habría sido de "; 
    cout << costeMinimoPosible(regsDiarios,numregs) << "€ ";
    cout << "(un "<< 100 - (costeMinimoPosible(regsDiarios,numregs) * 100) / costeTerminoVariable(regsDiarios,numregs)<< " % menor)" << endl;
    cout << "COSTE CON TARIFAS COMERCIALES" << endl;
    cout << "Coste "<<"Nombre de la tarifa" << endl;
    cout << "--------------------------------------------" << endl;
    for (unsigned i = 0; i < NUM_TARIFAS_COMERCIALES; i++)
    {
       cout << costeTarifaPlanaTramos(regsDiarios,numregs,TARIFAS_COMERCIALES[i]) << " €     "<< TARIFAS_COMERCIALES[i].nombre << endl; 
    }
     
 }
/*
 * ¡ESCRIBID LA ESPECIFICACIÓN DE ESTA FUNCIÓN!
 */
int main() {
    string usuario;
    unsigned mesIni;
    unsigned mesFinal;
    unsigned numregs;
    string nombreFich;
    string fichero = "tarifas-2021-ene-nov.csv";
    GastoDiario regsDiarios[MAX_DIAS];
    pedirDatos(usuario, mesIni, mesFinal);
    numregs = diasTranscurridos({1,mesIni,AGNO_ACTUAL},{1,mesFinal+1,AGNO_ACTUAL});
    leerPrecios(fichero,mesIni,mesFinal,regsDiarios);
    leerConsumos(usuario,mesIni,mesFinal, regsDiarios);
    pedirFich(nombreFich);
    
        //ofstream f{RUTA_DATOS+nombreFich};
        ofstream f;
        //if (f.is_open())
       //{
            escribirInforme(f,regsDiarios,numregs,usuario,mesIni,mesFinal);
            f.close();
       /*} else {
            cout << "Error al crear el archivo " << nombreFich;
        }
        
    } else {
        escribirEnPantalla(mesIni, mesFinal, usuario, regsDiarios, numregs);*/
    return 0;
}