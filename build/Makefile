# Directorios
SRC_DIR = ../src
BIN_DIR = .

# Nombre del ejecutable
TARGET = sistema_sicue

# Archivos fuente
SOURCES = $(SRC_DIR)/main.cc $(SRC_DIR)/alumno.cc $(SRC_DIR)/planAlumno.cc \
          $(SRC_DIR)/administrador.cc $(SRC_DIR)/profesor.cc $(SRC_DIR)/planProfesor.cc \
          $(SRC_DIR)/utilidades.cc
HEADERS = $(SRC_DIR)/alumno.h $(SRC_DIR)/planAlumno.h $(SRC_DIR)/administrador.h \
          $(SRC_DIR)/profesor.h $(SRC_DIR)/planProfesor.h $(SRC_DIR)/utilidades.h


# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Regla principal
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(BIN_DIR)/$(TARGET)

# Limpieza
clean:
	rm -f $(BIN_DIR)/$(TARGET)
