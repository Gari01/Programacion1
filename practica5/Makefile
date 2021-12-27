################################################################################
## Fichero «Makefile» para los programas de la práctica 5:
## «complejos», «juego-vida» y «bmp»
################################################################################

################################################################################
## Declaracion de variables del fichero «Makefile»

## DIRECTORIOS
SOURCE_DIR = src
BUILD_DIR = build
BIN_DIR = bin

VPATH = $(SOURCE_DIR) 

## COMPILADOR Y OPCIONES DE COMPILACIÓN:
CXX = g++
CXXFLAGS = -g -Wall -Wextra


## FICHEROS OBJETO (RESULTADOS INTERMEDIOS DE COMPILACIÓN):
BMP_OBJECTS = $(addprefix $(BUILD_DIR)/, imagen-bmp.o imagen-bmp-main.o )

################################################################################
## Reglas del fichero «Makefile»

complejos: $(SOURCE_DIR)/complejos.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCE_DIR)/complejos.cpp -o $(BIN_DIR)/$@

juego-vida: $(SOURCE_DIR)/juego-vida.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCE_DIR)/juego-vida.cpp -o $(BIN_DIR)/$@

bmp: $(BMP_OBJECTS) | $(BIN_DIR)
	$(CXX) -g $(BMP_OBJECTS) -o $(BIN_DIR)/$@ 

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@  

$(BUILD_DIR)/imagen-bmp.o: imagen-bmp.hpp
$(BUILD_DIR)/imagen-bmp-main.o: imagen-bmp.hpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -f $(OBJECTS) $(BIN_DIR)/*
endif
