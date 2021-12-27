################################################################################
## Fichero «Makefile» para:
##  - el programa «calculadora»
##  - el programa de pruebas del módulo «calculos»
##
## Este fichero es más complejo que el «Makefile» del repositorio
## correspondiente al tema 7
## (https://github.com/prog1-eina/tema-07-desarrollo-modular/blob/master/Makefile)
## Sí es objetivo de la asignatura que comprendais los conceptos que se manejan
## en el «Makefile» del tema 7, pero NO DE ESTE. No obstante, este fichero se
## encuentra SOBREDOCUMENTADO por si tienes interés en entener cómo está hecho.
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS

# Variable que define el directorio del código fuente del proyecto «calculadora»
SOURCE_DIR = src/calculadora

# Variable que define el directorio donde está el código fuente de las pruebas 
# del módulo «calculos»
TEST_DIR = test/calculadora

# Variable que define el directorio donde está el código fuente de una 
# biblioteca para mostar los resultados de las pruebas de los programas de pruebas
TESTING_LIB_DIR = test/testing-prog1

# Variable que define el directorio en el que crear los ficheros intermedios 
# de compilación
BUILD_DIR = build

# Variable que define el directorio en el que crear los ficheros ejecutables 
BIN_DIR = bin

# Variable preestablecida de «make» que en la que se pueden definir los 
# directorios en los que pueden hallarse los ficheros de codigo fuente a 
# compilar, con el objetivo de evitar tenerlos que poner de forma explícita
# en las reglas. 
# En este caso, son el directorio de codigo fuente («src/calculadora») y el 
# directorio de código para pruebas («test/calculadora» y «test/testing-prog1»).
VPATH = $(SOURCE_DIR) $(TEST_DIR) $(TESTING_LIB_DIR)


## COMPILADOR Y OPCIONES DE COMPILACIÓN:

# Variable preestablecida de «make» que en la que se puede definir el nombre del
# compilador. Esto permite que «make» genere recetas y reglas por defecto. 
CXX = g++

# Variable preestablecida de «make» que en la que se puede definir las opciones
# con las que debe invocarse al compilador.
# En este caso, son las siguientes:
#    -g:   indica al compilador que incluya información de depuración al generar
#          los ejecutables o los ficheros intermedios de compilación. Esta 
#          información es necesaria si luego se quiere utilizar el depurador.
#    -Wall:  indica al compilador que informe de todos los 
#          _warnings_ (advertencias o usos del lenguaje que, pese a ser
#          sintácticamente correctos, plantean un problema que casi siempre
#          resulta ser un error.
#    -Wextra:   indica al compilador que informe de algunos tipos de 
#          advertencias adicionales.
#    -I _directorio_:  indica al compilador que, cuando encuentre una cláusula
#          de inclusión de un fichero, si este no se encuentra en el directorio
#          actual, busque también en el directorio _dir_. En este caso, los
#          ficheros de cabecera .hpp pueden estar en «src/calculadora» o en
#          «test/testing-prog1».
CXXFLAGS = -g -Wall -Wextra -I$(SOURCE_DIR) -I$(TESTING_LIB_DIR)


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):

# Variables para definir la lista de ficheros objeto de los que depende el
# programa principal.
# En este caso, son los ficheros build/calculadora-main.o y build/calculos.o.
OBJECTS =  $(addprefix $(BUILD_DIR)/, calculos.o calculadora-main.o)

# Variable que define la lista de ficheros objeto de los que depende el programa
# de pruebas del módulo «calculos»: los ficheros «build/calculos-test-main.o», 
# «build/calculos-test.o», «build/testing-prog1.o» y «build/calculos.o».
TESTING_OBJECTS = $(addprefix $(BUILD_DIR)/,calculos-test-main.o \
                    calculos-test.o testing-prog1.o calculos.o)

################################################################################
## Reglas del fichero «Makefile»

# Regla utilizada habitualmente como primera regla, para indicar cuál es el
# objetivo final de la compilación.
# Esta regla indica el objetivo final es generar el fichero «calculadora» 
# (o «calculadora.exe» en Windows) 
all: calculadora

# Regla para construir el objetivo «calculadora» («calculadora.exe» en Windows).
# Tiene como prerrequisitos los ficheros «build/calculadora-main.o» y 
# «build/calculos.o», establecidos a partir de la variable $(OBJECTS) definida 
# anteriormente. También establece un prerrequisito especial: que el objetivo 
# $(BIN_DIR) (en este caso, el directorio «bin») simplemente exista.
# Más adelante en el fichero «Makefile» hay reglas para cada uno de los 
# objetivos de la lista $(OBJECTS) y para el objetivo $(BIN_DIR).
# La receta correspondiente a la regla «calculadora» establece como compilar los
# elementos de la lista $(OBJECTS) para generar «calculadora» 
# (o «calculadora.exe»)
calculadora: $(OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(OBJECTS) -o $(BIN_DIR)/calculadora 

# Sin utilizar varibles, la regla podría haberse escrito así:
# calculadora: build/calculadora-main.o build/calculos.o | bin
#	g++ -g build/calculadora-main.o build/calculos.o \
#		-o bin/calculadora 


# Regla para construir el objetivo «calculos-test» («calculos-test.exe» en 
# Windows), el programa de pruebas del módulo «calculos».
# Tiene como prerrequisitos los ficheros «build/calculos-test-main.o», 
# «build/calculos-test.o», «build/testing-prog1.o» y «build/calculos.o»,
# establecidos a partir de la variable $(TESTING_OBJECTS) definida 
# anteriormente. También establece un prerrequisito especial: que el objetivo
# $(BIN_DIR).
# La receta correspondiente a la regla, establece como compilar los elementos
# de la lista $(TESTING_OBJECTS) para generar «calculos-test»
# (o «calculos-test.exe»)
calculos-test: $(TESTING_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(TESTING_OBJECTS) -o $(BIN_DIR)/calculos-test

# Sin utilizar varibles, la regla podría haberse escrito de forma más larga y
# menos mantenible por la repetición de los nombres de los ficheros
# involucrados:
# calculos-test: build/calculos-test-main.o build/calculos-test.o \
#                build/testing.o build/calculos.o | bin
#	g++ -g build/calculos-test-main.o build/calculos-test.o \
#		 build/testing-prog1.o build/calculos.o -o bin/calculos-test


# Regla implícita que establece de forma general la forma de generar cualquier
# objetivo de la carpeta «build» que tenga la extensión «.o»: tiene como
# prerrequisito un fichero del mismo nombre, pero con la extensión «.cpp», que 
# puede ubicarse en cualquier directorio de la variable $(VPATH). También tiene
# como prerrequisito especial que exista el directorio «build». Establece como
# receta ejecutar el programa g++, con los parámetros establecidos en la
# variable $(CXXFLAGS), compilando el código fuente del fichero con la extensión
# «.cpp» (la variable automática $< representa el nombre del fichero
# correspondiente al primer prerrequisito de la regla) para generar el fichero
# correspondiente al objetivo de la regla (representado por la variable
# automática $@). 
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

# Con reglas simples, hubieran hecho falta cinco reglas distintas, pero muy
# similares entre sí, correspondientes a los cinco ficheros objeto con los que
# puede llegar a trabajar este «Makefile».  	

# Reglas que establecen prerrequisitos adicionales para algunos de los 
# objetivos. Están representando el hecho de que algunos ficheros objeto 
# dependen no solo de su correspondiente fichero «.cpp», sino también de
# algún fichero de cabecera de módulos de los que son dependientes:
$(OBJECTS): calculos.hpp 
$(BUILD_DIR)/calculos-test-main.o: calculos-test.hpp 
$(BUILD_DIR)/calculos-test.o: testing-prog1.hpp calculos.hpp
$(BUILD_DIR)/testing-prog1.o: testing-prog1.hpp


# Reglas con objetivo pero sin prerrequisitos, que establecen cómo crear 
# los directorios bin y build.
$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
