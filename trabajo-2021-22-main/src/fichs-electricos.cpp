/******************************************************************************\
 * Curso de Programación 1. Tema 11 (Registros) y trabajo obligatorio 2021-22
 * Autores: Gari Arellano y Alain Cascán
 * Última revisión: 28 de diciembre de 2021
 * Resumen: Fichero de implementación «fichs-electricos.cpp» del módulo «fichs-electricos».
\******************************************************************************/

#include <fstream>
#include <iostream>
#include "fecha.hpp"
#include "gasto-diario.hpp"
using namespace std;

const string RUTA_DATOS = "datos/";


/*
 * Pre:  «f» está asociado con un fichero externo que cumple con la sintaxis de
 *       la regla <fichero-precios> establecida en el enunciado y está en
 *       disposición de leer desde el principio de una línea que cumple con la
 *       regla <precio-horario>.
 * Post: Ha extraido de «f» la línea a la que hacía referencia la precondición
 *       y ha asignado a los parámetros «fecha», «hora» y «precio»,
 *       respectivamente, los datos sobre la fecha, hora y precio horario
 *       correspondientes a la línea que se ha extraído del flujo «f».
 *       El flujo «f» continua asociado con el fichero externo y en disposición
 *       de extraer datos a partir de la siguiente línea.
 *       La función ha devuelto «true» si no se han terminado los datos del
 *       fichero en el intento de lectura y «false» en caso contrario.
 */
bool leerPrecioHorario(istream& f, Fecha& fecha, unsigned& hora, double& precio){
    string basura;
    if (getline(f,basura,';')) // Primero compruebo si hay un ID que podamos leer, en caso afirmativo continuamos con la lectura del flujo.
    {
        for (unsigned i = 0; i < 3; i++)
        {
            getline(f,basura,';'); // Eliminamos la información que no necesitamos, en este caso, son 4 columnas lo que no nos interesa.
        }
        f >> precio;
        f.get(); // Elimino el ;
        f >> fecha.agno;
        f.get(); // Elimino el ;
        f >> fecha.mes;
        f.get(); // Elimino el ;
        f >> fecha.dia;
        f.get(); // Elimino el T
        f >> hora;
        getline(f,basura);
        return true; // Si hemos podido leer correctamente, devolvemos un true.
    }
    return false; // Si llegamos a este punto, es porque no se ha devuelto el true, entonces significa que la lectura ha fallado.
}
/*
 * Pre:  «f» está asociado con un fichero externo que cumple con la sintaxis de
 *       la regla <fichero-consumos> establecida en el enunciado y está en
 *       disposición de leer desde el principio de una línea que cumple con la
 *       regla <consumo-horario>.
 * Post: Ha extraido de «f» la línea a la que hacía referencia la precondición
 *       y ha asignado a los parámetros «fecha», «hora» y «consumo»,
 *       respectivamente, los datos sobre la fecha, hora y consumo horario
 *       correspondientes a la línea que se ha extraído del flujo «f». 
 *       El flujo «f» continua asociado con el fichero externo y en disposición
 *       de extraer datos a partir de la siguiente línea.
 *       La función ha devuelto «true» si no se han terminado los datos del
 *       fichero en el intento de lectura y «false» en caso contrario.
 */
bool leerConsumoHorario(istream& f, Fecha& fecha, unsigned& hora, double& consumo){
    string basura;
    if (getline(f,basura,';')) // Primero compruebo si hay un CUPS que podamos leer, en caso afirmativo continuamos con la lectura del flujo.
    {
        f >> fecha.dia;
        f.get(); // Elimino el / 
        f >> fecha.mes;
        f.get(); // Elimino el / 
        f >> fecha.agno;
        f.get(); // Elimino el / 
        f >> hora;
        hora -=1;
        f.get(); // Elimino el ;
        f >> consumo;
        getline(f,basura);
        return true; // Si hemos podido leer correctamente, devolvemos un true.
    }
    return false; // Si llegamos a este punto, es porque no se ha devuelto el true, entonces significa que la lectura ha fallado.
}
/*
 * Pre:  «nombreFichero» es el nombre de un fichero externo que cumple con la
 *       sintaxis de la regla <fichero-precios> establecida en el enunciado; 
 *       «mesInicial» y «mesFinal» están ambos entre «PRIMER_MES» y «ULTIMO_MES»
 *       y mesInicial < mesFinal.
 * Post: Ha copiado los datos de precios horarios correspondientes a fechas 
 *       entre «mesInicial» y «mesFinal» presentes en «nombreFichero» en las 
 *       componentes correspondientes a la hora del precio del campo «precios»
 *       en las primeras componentes del vector «registros», cuyos campos
 *       «fecha» se han actualizado y han quedado en orden cronológico (tal y
 *       como aparecían en el fichero). LOS DATOS DEL VECTOR CORRESPONDIENTE AL
 *       CAMPO «CONSUMO» NO SE HAN MODIFICADO.
 *       La función ha devuelto «true» si ha podido leer del fichero de nombre 
 *       «nombreFichero» correctamente, y «false» en caso contrario.
 */
bool leerPrecios(const string nombreFichero, const unsigned mesInicial, const unsigned mesFinal, GastoDiario registros[]){
    ifstream f(RUTA_DATOS+nombreFichero);
    if (f.is_open())
    {
        string basura;
        Fecha fechaini = {1,mesInicial,2021};
        Fecha fechaLeida;
        double coste;
        unsigned hora;
        getline(f,basura);
        while (leerPrecioHorario(f,fechaLeida,hora,coste))
        {
            if (fechaLeida.mes >= mesInicial && fechaLeida.mes <= mesFinal)
            {
                unsigned indice = diasTranscurridos(fechaini,fechaLeida);
                registros[indice].precioDia[hora] = coste/1000;
                registros[indice].fecha = fechaLeida;
            }
        }
        f.close();
        return true;
    } else {
        cout << "Error al leer el archivo "+nombreFichero;
    }
    return false;
}
/*
 * Pre:  «mesInicial» y «mesFinal» están ambos entre «PRIMER_MES» y «ULTIMO_MES»
 *       y mesInicial < mesFinal; si para cada mes entre «mesInicial» y
 *       «mesFinal» existe un fichero con nombre de la forma
 *       "datos/" + nombreCliente + "-2021-" + mes-con-dos-cifras + ".csv", este
 *       cumple con la sintaxis de la regla <fichero-consumos> establecida en el
 *       enunciado.
 * Post: Ha copiado los datos de precios horarios correspondientes a fechas 
 *       entre «mesInicial» y «mesFinal» presentes en los ficheros mencionados
 *       en la precondición en las componentes correspondientes a la hora del
 *       consumo del campo «consumo» en las primeras componentes del vector
 *       «registros». LOS DATOS DEL VECTOR CORRESPONDIENTE AL CAMPO «PRECIOS» NO
 *       SE HAN MODIFICADO.
 *       La función ha devuelto «true» si ha podido leer de todos los ficheros 
 *       referidos en la precondición correctamente, y «false» en caso contrario.
 */
bool leerConsumos(const string nombreCliente, const unsigned mesInicial, const unsigned mesFinal, GastoDiario registros[]){
    string nombreFich = "-2021-";
    string extensionFich = ".csv";
    unsigned hora;
    double coste;
    Fecha fechaLeida;
    Fecha fechaini = {1,mesInicial,2021};
    bool flag = 0;
    unsigned i = mesInicial;
    string basura;
    while (i <= mesFinal && flag == 0)
    {
        if (i < 10)
        {
            nombreFich = "-2021-0";
        } else {
            nombreFich = "-2021-";
        }
        ifstream f{RUTA_DATOS+nombreCliente+nombreFich+to_string(i)+extensionFich};
        if (f.is_open())
        {
            getline(f,basura); // Eliminamos la primera linea
            while (leerConsumoHorario(f,fechaLeida,hora,coste))
            {
                unsigned indice = diasTranscurridos(fechaini,fechaLeida);
                registros[indice].consElect[hora] = coste/1000;
                registros[indice].fecha = fechaLeida;
            }
            f.close();
        } else {
            flag = 1;
        }
        i++;
    }
    if (flag == 1)
    {
        cout << "Error al leer el archivo "+ nombreCliente+nombreFich+extensionFich;
        return false;
    }
    return true;
}

