# Práctica 3 de Programación 1

## Escuela de Ingeniería y Arquitectura. Universidad de Zaragoza 

Código fuente de partida para las tareas de la 3ª práctica de Programación 1.

Puede clonarse o descargarse en formato ZIP. 

En Visual Stuido Code hay que abrir el directorio ``practica3``.

Contiene el código de cuatro programas:

1. Programa ``calculadora``. Para compilarlo y ejecutarlo desde la terminal en Linux y macOS:
    ```
    make 
    bin/calculadora
    ```

2. Programa de pruebas ``calculos-test``. Para compilarlo y ejecutarlo desde la terminal en Linux y macOS:
    ```
    make calculos-test
    bin/calculos-test
    ```

3. Programa ``calendario``. Para compilarlo y ejecutarlo desde la terminal en Linux y macOS:
    ```
    make calendario -f calendario.mk
    bin/calendario
    ```

4. Programa de pruebas ``fechas-test``. Para compilarlo y ejecutarlo desde la terminal en Linux y macOS:
    ```
    make fechas-test -f calendario.mk
    bin/fechas-test
    ```

En Windows habría que compilar con ``mingw32-make`` en lugar de ``make``. En terminales del símbolo del sistema y no PowerShell, habría que ejecutar separando directorios con `\` en lugar de `/` (por ejemplo, `bin\calculadora` en lugar de `bin/calculadora`).

Se han configurado tareas en Visual Studio Code que permiten compilar, ejecutar y depurar cualquiera de los cuatro programas de este repositorio. Están accesibles a través del menú `Terminal` > `Run Task`.