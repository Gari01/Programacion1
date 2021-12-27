/******************************************************************************\
 * Programación 1. Práctica 5
 * Autores: Miguel Ángel Latre y Rafael Tolosana
 * Modificado por: ¡¡¡PON AQUÍ TU NOMBRE!!!
 * Ultima revisión: 21 de noviembre de 2020
 * Resumen: Fichero de implementación del módulo principal del programa que 
 *          manipula imágenes BMP en la 5ª práctica.
 * Nota: El código de este programa está repartido en varios módulos.
 *       Para compilarlo, hay que ejecutar el comando
 *           make bmp
 *       o, en Windows,
 *           mingw32-make bmp
 *       o ejecutar la tarea "Compilar «bmp»" de VSC.
 * 
 *       Para ejecutarlo, una vez compilado, hay que ejecutar el comando
 *           bin/bmp
 *       o, en Windows,
 *           bin\bmp.exe
 *       o ejecutar la tarea "Ejecutar «bmp»" de VSC.
\******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include "imagen-bmp.hpp"
using namespace std;

/*
Pre: 
Post: Imprime por pantalla un mensaje solicitando que se introduzca la direccion de donde obtener la imagen.
*/
void PedirDatos(string& nombreFichero) {
    cout << "Escriba el nombre de un fichero BMP: ";
    cin >> nombreFichero;
}
/*
Pre: 
Post: Utilizando la imagen que se le pasa a la funcion, crea una imagen rotada.
*/
void rotarImagen(Imagen& img) {
    for (int i = 0; i < img.alto/2; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            Pixel auxiliar = img.pixels[i][j];
            img.pixels[i][j] = img.pixels[img.alto - 1 - i][img.ancho - 1 - j];
            img.pixels[img.alto - 1 - i][img.ancho - 1 - j] = auxiliar;
        }   
    }
    cout << "Imagen creada con éxito.";
}
/*
Pre: 
Post: Utilizando la imagen que se le pasa a la funcion, crea una imagen negativizada.
*/
void negativizarImagen(Imagen& img) {
    for (int i = 0; i < img.alto; i++)
    {
        for (int j = 0; j < img.ancho; j++)
        {
            img.pixels[i][j].rojo = 255 - img.pixels[i][j].rojo;
            img.pixels[i][j].verde = 255 - img.pixels[i][j].verde;
            img.pixels[i][j].azul = 255 - img.pixels[i][j].azul;
        }   
    }
    cout << "Imagen creada con éxito.";
}
/*
Pre: 
Post: Programa al que le introduces una dirección donde obtener una imagen y da dos opciones. Una para rotar la imagen y otra para 
* negativizarla. Finalmente se guarda la imagen con el nombre que el usuario le escriba.
*/
int main() {
    static Imagen img;
    string nombreFichero = "datos/prog1.bmp";
    string nombreFicheroDestino;
    char opcion;
    PedirDatos(nombreFichero);
    if (leerImagen(nombreFichero, img)) {
        cout << "Imagen" << nombreFichero << "leída con éxito.";
        do
        {
            cout << "Escriba una opción (N - negativizar; R - rotar): ";
            cin >> opcion;
            opcion = toupper(opcion);
            cout << "Escriba el nombre del fichero destino: ";
            cin >> nombreFicheroDestino;
        } while (opcion != 'R' && opcion != 'N');
        if (opcion == 'R')
        {
            rotarImagen(img);
        } else {
            negativizarImagen(img);
        }
        guardarImagen(nombreFicheroDestino, img);
        return 0;
    }
    else {
        cout << "No se ha encontrado el fichero " << "\n'' "<< nombreFichero << "\n'' "<< endl;
        return 1;
    }
}