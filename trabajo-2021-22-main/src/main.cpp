/******************************************************************************\
 * Programación 1. Trabajo obligatorio curso 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Ultima revisión: ¡¡¡!!!
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
const unsigned diasMaxAgno = 366;


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
void pedirFich(string& nombreFich){
    cout << "Escriba el nombre del fichero del informe" << endl;
    cout << "(presione solo ENTRAR para escribirlo en la pantalla): ";
    char enter;
    cin.ignore();
    cin.get(enter);
    if ( enter == '\n')
    {
        cout << "Hola";
    } else {
        cin >> nombreFich;
        nombreFich = enter+nombreFich;
        // Escribir en un fichero.
    }
}

void escribirEnPantalla (const unsigned& mesIni, const unsigned& mesFinal, const string& usuario, GastoDiario regsDiarios[diasMaxAgno]){
    cout << endl << endl << "INFORME DEL CLIENTE " << usuario << " ENTRE LOS MESES " << mesIni << " Y " << mesFinal << " DE 2021" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    double precioMinimo;
    Fecha fecha;
    unsigned numregs = diasTranscurridos({1,mesIni,2021},{1,mesFinal+1,2021}); // Hay que crear constante de año.
    diaMasBarato(regsDiarios,numregs,fecha,precioMinimo);
    cout << "El día completo más barato fue el " << fecha.dia << "-" << fecha.mes << "-2021" << " . Precio medio: " << precioMinimo << " €/kWh";
}
/*
 * ¡ESCRIBID LA ESPECIFICACIÓN DE ESTA FUNCIÓN!
 */
int main() {
    string usuario;
    unsigned mesIni;
    unsigned mesFinal;
    string nombreFich;
    GastoDiario regsDiarios[diasMaxAgno];
    pedirDatos(usuario, mesIni, mesFinal);
    pedirFich(nombreFich);
    string fichero = "tarifas-2021-ene-nov.csv";
    leerPrecios(fichero,mesIni,mesFinal,regsDiarios);
    leerConsumos(usuario,mesIni,mesFinal, regsDiarios);
    escribirEnPantalla(mesIni, mesFinal, usuario,regsDiarios);
    return 0;
}