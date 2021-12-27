/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Ultima revisión: 17 de noviembre de 2021
 * Resumen: Fichero de implementación «imagen.hpp» de un módulo denominado
 *          «imagen» para trabajar con imágenes BMP
 *          en la 5ª práctica.
\******************************************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include "imagen-bmp.hpp"
using namespace std;


void leerPixels(ifstream& f, Imagen& imagen) {
    for (unsigned i = 0; i < imagen.alto; i++) {
        for (unsigned j = 0; j < imagen.ancho; j++) {
            f.get(imagen.pixels[i][j].rojo);
            f.get(imagen.pixels[i][j].verde);
            f.get(imagen.pixels[i][j].azul);
        }
    }
}

/*
 * Pre:  «nombreFichero» es un fichero binario en formato BMP 
 * Post: Si existe el fichero «nombreFichero» y este tiene unas dimensiones
 *       correctas, tras ejecutar este procedimiento, «imagen» almacena en
 *       memoria la imagen almacenada en un fichero binario en formato BMP y la
 *       función ha devuelto true. En caso contrario, ha devuelto false y ha
 *       escrito en la pantalla un mensaje de error indicando la causa del mismo.
 */
bool leerImagen(const string nombreFichero, Imagen& imagen) {
    ifstream f(nombreFichero, ios::binary);
    if (f.is_open()){
        f.read(imagen.cabecera_parte1, TAM_CABECERA_1);
        if (imagen.cabecera_parte1[0] == 'B' && imagen.cabecera_parte1[1] == 'M') {
            f.read(reinterpret_cast<char*>(&imagen.ancho), sizeof(unsigned));
            if (imagen.ancho <= MAX_ANCHO && imagen.ancho % 4 == 0) {
                f.read(reinterpret_cast<char*>(&imagen.alto), sizeof(unsigned));
                if (imagen.alto <= MAX_ALTO && imagen.alto % 4 == 0) {
                    f.read(imagen.cabecera_parte2, TAM_CABECERA_2); 
                    leerPixels(f, imagen);
                    cout << "Imagen \"" << nombreFichero << "\" leída con éxito." 
                         << endl;
                    f.close();
                    return true;
                }
                else {
                    f.close();
                    cout << "El fichero \"" << nombreFichero 
                         << "\" tiene una altura de " << imagen.alto 
                         << " píxeles, que es superior al máximo de " << MAX_ALTO 
                         << ", o no es múltiplo de 4. " << endl;
                    return false;
                }
            }
            else {
                f.close();
                cout << "El fichero \"" << nombreFichero 
                     << "\" tiene una anchura de " << imagen.ancho 
                     << " píxeles, que es superior al máximo de " << MAX_ANCHO 
                     << ", o no es múltiplo de 4. " << endl;
                return false;
            }
        }
        else {
            f.close();
            cout << "El contenido del fichero \"" << nombreFichero 
                 << "\" no sigue el formato BMP." << endl;
            return false;
        }
    }
    else {
        cout << "No se ha encontrado el fichero \"" << nombreFichero << "\"."
             << endl;
        return false;
    }
}


/*
 * Pre:  ---
 * Post: Tras ejecutar este procedimiento, almacena en disco en un fichero de 
 *       nombre «nombreFichero» la imagen BMP de «imagen».
 */
void guardarImagen(const string nombreFichero, Imagen imagen) {
    ofstream f(nombreFichero, ios::binary);
    if (f.is_open()) {
        f.write(imagen.cabecera_parte1, TAM_CABECERA_1);
        f.write(reinterpret_cast<char*>(&imagen.ancho), sizeof(unsigned));
        f.write(reinterpret_cast<char*>(&imagen.alto),  sizeof(unsigned));
        f.write(imagen.cabecera_parte2, TAM_CABECERA_2); 
        for (unsigned i = 0; i < imagen.alto; i++){
            for (unsigned j = 0; j < imagen.ancho; j++){
                f.put(imagen.pixels[i][j].rojo);
                f.put(imagen.pixels[i][j].verde);
                f.put(imagen.pixels[i][j].azul);
            }
        }
        cout << "Imagen \"" << nombreFichero << "\" creada con éxito." << endl;
    }
    else {
        cerr << "No se ha podido guardar la imagen \"" << nombreFichero << "\"."
             << endl;
    }
    f.close();
}
