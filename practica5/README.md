# Práctica 5 de Programación 1

Datos y código fuente de partida para la 5ª práctica de [Programación 1](https://github.com/prog1-eina) ([Grado en Ingeniería Informática](https://webdiis.unizar.es/~silarri/coordinadorGrado/), [Escuela de Ingeniería y Arquitectura](https://eina.unizar.es/), [Universidad de Zaragoza](https://www.unizar.es/)).

Puede clonarse o descargarse en formato ZIP y abrirse en Visual Studio Code, a través de la opción de menú File > Open Folder... y seleccionado el directorio ``practica5``.

El enunciado puede consultarse [aquí](./practica5.pdf).

## Compilación y ejecución

### Programas ``complejos`` y ``juego-vida``

El código de los programas ``complejos`` y ``juego-vida`` está contenido en un único fichero, por lo que se puede utilizar la extensión Code Runner de VSC para ejecutarlos .

No obstante, se han configurado reglas en el fichero ``Makefile`` para poder compilarlos:

    make complejos

o

    make juego-vida

También se han definido tareas de VSC para compilarlos, ejecutarlos y depurarlos:

- ``Compilar «complejos»``
- ``Ejecutar «complejos»``
- ``Depurar «complejos»``

- ``Compilar «juego-vida»``
- ``Ejecutar «juego-vida»``
- ``Depurar «juego-vida»``

### Programa ``bmp``

El código de este programa está repartido en varios módulos. Para compilarlo, hay que ejecutar el comando

    make bmp

o, en Windows,

    mingw32-make bmp

o ejecutar la tarea ``Compilar «bmp»`` de VSC.

Para ejecutarlo, una vez compilado, hay que ejecutar el comando

    bin/bmp

o, en Windows,

    bin\bmp.exe

o ejecutar la tarea ``Ejecutar «bmp»`` de VSC.
