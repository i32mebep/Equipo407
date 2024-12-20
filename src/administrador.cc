#include "administrador.h"
#include "planAlumno.h"
#include "planProfesor.h"
#include <iostream>
#include <fstream>
#include <vector>

// Constructor
Administrador::Administrador(const std::string& dni, const std::string& nombre, const std::string& email,
                             const std::string& apellido1, const std::string& apellido2)
    : Usuario(dni, nombre, email, apellido1, apellido2) {}

// Submenú para crear plan de convalidación
void Administrador::crearPlanDeConvalidacion() {
    int opcion;
    do {
        std::cout << "\n=== Crear Plan de Convalidación ===\n";
        std::cout << "1. Crear Plan para Alumnos\n";
        std::cout << "2. Crear Plan para Profesores\n";
        std::cout << "0. Volver\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                crearPlanDeConvalidacionAlumno();
                break;
            case 2:
                crearPlanDeConvalidacionProfesor();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

// Crear plan para alumnos
void Administrador::crearPlanDeConvalidacionAlumno() {
    std::string universidad, facultad, carrera;
    std::vector<std::pair<std::string, int>> asignaturas;

    std::cout << "Introduzca el nombre de la Universidad: ";
    std::cin.ignore();
    std::getline(std::cin, universidad);

    std::cout << "Introduzca el nombre de la Facultad: ";
    std::getline(std::cin, facultad);

    const std::vector<std::string> carreras = {
        "Grado en Informática",
        "Grado en Ingenieria Electrónica",
        "Grado en Matemáticas",
        "Grado en Física",
        "Grado en Química"
    };

    std::cout << "Seleccione una carrera:\n";
    for (size_t i = 0; i < carreras.size(); ++i) {
        std::cout << i + 1 << ". " << carreras[i] << "\n";
    }

    int opcionCarrera;
    std::cin >> opcionCarrera;
    if (opcionCarrera < 1 || opcionCarrera > 5) {
        std::cerr << "Opcion no valida.\n";
        return;
    }
    carrera = carreras[opcionCarrera - 1];

    std::cout << "Introduzca las asignaturas con sus créditos (escriba 'fin' para terminar):\n";
    std::string nombreAsignatura;
    int creditos;
    while (true) {
        std::cout << "Nombre de la asignatura: ";
        std::cin.ignore();
        std::getline(std::cin, nombreAsignatura);
        if (nombreAsignatura == "fin") break;

        std::cout << "Créditos: ";
        std::cin >> creditos;
        asignaturas.emplace_back(nombreAsignatura, creditos);
    }

    PlanAlumno plan(universidad, facultad, carrera, asignaturas);
    plan.mostrarResumenAlumno();
    plan.guardarEnArchivo("../data/planes_alumno.dat");
    std::cout << "Plan guardado correctamente.\n";
}

void Administrador::crearPlanDeConvalidacionProfesor() {
    std::string universidad, facultad, departamento, duracion;

    // Universidad y facultad introducidas manualmente
    std::cout << "Introduzca el nombre de la universidad: ";
    std::cin.ignore();
    std::getline(std::cin, universidad);

    std::cout << "Introduzca el nombre de la facultad: ";
    std::getline(std::cin, facultad);

    // Lista de departamentos predefinidos
    const std::vector<std::string> departamentos = {
        "Matemáticas",
        "Física Aplicada",
        "Informática y Análisis Numérico",
        "Ingeniería Electrónica",
        "Química Orgánica"
    };

    std::cout << "Seleccione un departamento:\n";
    for (size_t i = 0; i < departamentos.size(); ++i) {
        std::cout << i + 1 << ". " << departamentos[i] << "\n";
    }

    int opcionDepartamento;
    std::cin >> opcionDepartamento;

    if (opcionDepartamento < 1 || opcionDepartamento > (int)departamentos.size()) {
        std::cerr << "Opción no válida.\n";
        return;
    }
    departamento = departamentos[opcionDepartamento - 1];

    // Opciones para la duración
    std::cout << "Seleccione la duración del plan:\n";
    std::cout << "1. Cuatrimestral\n";
    std::cout << "2. Año completo\n";

    int opcionDuracion;
    std::cin >> opcionDuracion;

    if (opcionDuracion == 1) {
        duracion = "Cuatrimestral";
    } else if (opcionDuracion == 2) {
        duracion = "Año completo";
    } else {
        std::cerr << "Opción no válida.\n";
        return;
    }

    // Crear y guardar el plan
    PlanProfesor plan(universidad, facultad, departamento, duracion);
    plan.mostrarResumenProfesor();
    plan.guardarEnArchivo("../data/planes_profesor.dat");
    std::cout << "Plan guardado correctamente.\n";
}