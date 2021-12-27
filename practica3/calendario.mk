################################################################################
## Fichero «Makefile» para:
##  - el programa «calendario»
##  - el programa de pruebas del módulo «fechas»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS

SOURCE_DIR = src/calendario
TEST_DIR = test/calendario
TESTING_LIB_DIR = test/testing-prog1
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) $(TEST_DIR) $(TESTING_LIB_DIR)

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra -I$(SOURCE_DIR) -I$(TESTING_LIB_DIR)

## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
OBJECTS = $(addprefix $(BUILD_DIR)/, calendario-main.o fechas.o)

TESTING_OBJECTS = $(addprefix $(BUILD_DIR)/, fechas-test-main.o \
                    fechas-test.o testing-prog1.o fechas.o)

################################################################################
## Reglas del fichero «Makefile»
all: calendario

calendario: $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BIN_DIR)/calendario 

fechas-test: $(TESTING_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TESTING_OBJECTS) -o $(BIN_DIR)/fechas-test

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(OBJECTS): fechas.hpp 
$(BUILD_DIR)/fechas-test-main.o: fechas-test.hpp 
$(BUILD_DIR)/fechas-test.o: testing-prog1.hpp fechas.hpp
$(BUILD_DIR)/testing-prog1.o: testing-prog1.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
