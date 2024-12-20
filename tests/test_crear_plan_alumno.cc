#include "../src/planAlumno.h"
#include "../src/utilidades.h"
#include "../src/administrador.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

// Test para crear un plan de convalidación de alumno
void testCrearPlanAlumno() {
    std::cout << "=== Test Crear Plan de Convalidación de Alumno ===\n";

    // Crear un objeto Administrador para realizar la prueba
    Administrador admin("12345678A", "Admin", "admin@correo.com", "Apellido1", "Apellido2");

    // Simular la creación de un plan de convalidación para alumnos
    std::cout << "\nSimulando la creación de un plan...\n";
    admin.crearPlanDeConvalidacionAlumno();

    // Comprobar si el plan fue guardado correctamente
    std::ifstream archivo("../data/planes_alumno.dat");
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo de planes de alumnos.\n";
        std::cout << "Test Crear Plan de Alumno: FALLADO\n";
        return;
    }

    std::string linea;
    bool planEncontrado = false;
    while (std::getline(archivo, linea)) {
        if (linea.find("Carrera:") != std::string::npos) {
            planEncontrado = true;
            break;
        }
    }
    archivo.close();

    if (planEncontrado) {
        std::cout << "Plan creado y guardado correctamente.\n";
        std::cout << "Test Crear Plan de Alumno: PASADO\n";
    } else {
        std::cerr << "Error: No se encontró el plan creado en el archivo.\n";
        std::cout << "Test Crear Plan de Alumno: FALLADO\n";
    }
}