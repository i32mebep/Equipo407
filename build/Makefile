# Directorios
SRC_DIR = ../src
BIN_DIR = .
TESTS_DIR = ../tests

# Nombre del ejecutable principal
TARGET = sistema_sicue

# Archivos fuente principales
SOURCES = $(SRC_DIR)/main.cc $(SRC_DIR)/alumno.cc $(SRC_DIR)/planAlumno.cc \
          $(SRC_DIR)/administrador.cc $(SRC_DIR)/profesor.cc $(SRC_DIR)/planProfesor.cc \
          $(SRC_DIR)/utilidades.cc
HEADERS = $(SRC_DIR)/alumno.h $(SRC_DIR)/planAlumno.h $(SRC_DIR)/administrador.h \
          $(SRC_DIR)/profesor.h $(SRC_DIR)/planProfesor.h $(SRC_DIR)/utilidades.h

# Archivos de prueba
TEST_SOURCES = $(TESTS_DIR)/test_inscripcion_alumno.cc $(TESTS_DIR)/test_inscripcion_duplicada.cc \
               $(TESTS_DIR)/test_crear_plan_alumno.cc
TEST_BINS = $(BIN_DIR)/test_inscripcion_alumno $(BIN_DIR)/test_inscripcion_duplicada \
            $(BIN_DIR)/test_crear_plan_alumno

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Regla principal: compila el sistema completo
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(BIN_DIR)/$(TARGET)

# Reglas para los tests
$(BIN_DIR)/test_inscripcion_alumno: $(SRC_DIR)/alumno.cc $(SRC_DIR)/planAlumno.cc \
                                    $(SRC_DIR)/utilidades.cc $(TESTS_DIR)/test_inscripcion_alumno.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/test_inscripcion_duplicada: $(SRC_DIR)/alumno.cc $(SRC_DIR)/planAlumno.cc \
                                       $(SRC_DIR)/utilidades.cc $(TESTS_DIR)/test_inscripcion_duplicada.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/test_crear_plan_alumno: $(SRC_DIR)/administrador.cc $(SRC_DIR)/planAlumno.cc \
                                   $(SRC_DIR)/utilidades.cc $(TESTS_DIR)/test_crear_plan_alumno.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/test_crear_plan_profesor: $(SRC_DIR)/administrador.cc $(SRC_DIR)/planProfesor.cc \
                                     $(SRC_DIR)/utilidades.cc $(TESTS_DIR)/test_crear_plan_profesor.cc
	$(CXX) $(CXXFLAGS) $^ -o $@


# Limpieza
clean:
	rm -f $(BIN_DIR)/$(TARGET) $(TEST_BINS)