#include "profesor.h"
#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // Para formatear la salida
#include <sstream>


Profesor::Profesor(const std::string& dni, const std::string& nombre, const std::string& apellido1,
                   const std::string& apellido2, const std::string& email, const std::string& departamento)
    : Usuario(dni, nombre, apellido1, apellido2, email), // Llamada al constructor de Usuario
      departamento(departamento) {}
// Solicitar Inscripción Profesor
void Profesor::solicitarInscripcionProfesor() {
    std::string dni, nombre, departamentoSeleccionado;

    // Solicitar DNI y nombre
    std::cout << "Introduzca su DNI: ";
    std::cin >> dni;
    std::cin.ignore();
    std::cout << "Introduzca su nombre: ";
    std::getline(std::cin, nombre);

    // Comprobar si ya existe una solicitud
    if (solicitudProfesorExistente(dni)) {
        std::cout << "Ya tiene una solicitud vigente.\nPresione Enter para volver...\n";
        std::cin.get();
        return;
    }

    // Departamentos predefinidos
    const std::vector<std::string> departamentos = {
        "Matemáticas", "Física Aplicada", "Informática y Análisis Numérico",
        "Ingeniería Electrónica", "Química Inorgánica"
    };

    std::cout << "\nSeleccione su departamento:\n";
    for (size_t i = 0; i < departamentos.size(); ++i) {
        std::cout << i + 1 << ". " << departamentos[i] << "\n";
    }

    int opcionDepto;
    std::cin >> opcionDepto;
    if (opcionDepto < 1 || opcionDepto > (int)departamentos.size()) {
        std::cerr << "Opción no válida.\n";
        return;
    }

    departamentoSeleccionado = departamentos[opcionDepto - 1];

    // Leer planes disponibles
    std::ifstream archivo("../data/planes_profesor.dat");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de planes.\n";
        return;
    }

    std::vector<std::string> planes;
    std::string linea, universidad, duracion, planCompleto;
    char letra = 'A';

    std::cout << "\nPlanes de Convalidación disponibles:\n";
    while (std::getline(archivo, linea)) {
        if (linea.find("Departamento: " + departamentoSeleccionado) != std::string::npos) {
            std::getline(archivo, universidad);
            std::getline(archivo, duracion);

            planCompleto = "Plan " + std::string(1, letra++) + ": " +
                           departamentoSeleccionado + ", " +
                           universidad.substr(12) + ", " + // Eliminar "Universidad: "
                           duracion.substr(10);           // Eliminar "Duracion: "

            planes.push_back(planCompleto);
            std::cout << planCompleto << "\n";
        }
    }
    archivo.close();

    if (planes.empty()) {
        std::cout << "No hay planes disponibles para el departamento seleccionado.\n";
        return;
    }

    // Selección de planes
    std::vector<std::string> seleccionados;
    char opcion;

    while (true) {
        std::cout << "Seleccione la letra del plan (0 para terminar): ";
        std::cin >> opcion;

        if (opcion == '0') break;

        int indice = opcion - 'A';
        if (indice >= 0 && indice < (int)planes.size()) {
            seleccionados.push_back(planes[indice]);
            std::cout << "Plan " << opcion << " agregado a su lista de preferencias.\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    if (seleccionados.empty()) {
        std::cout << "No ha seleccionado ningún plan.\n";
        return;
    }

    // Guardar la solicitud
    std::ofstream archivoSolicitud("../data/solicitud_profesor.dat", std::ios::app);
    if (!archivoSolicitud) {
        std::cerr << "Error al abrir el archivo de solicitudes.\n";
        return;
    }

    archivoSolicitud << "DNI: " << dni << "\n";
    archivoSolicitud << "Nombre: " << nombre << "\n";
    archivoSolicitud << "Fecha: " << obtenerFechaActual() << "\n";
    archivoSolicitud << "Preferencias:\n";

    for (size_t i = 0; i < seleccionados.size(); ++i) {
        archivoSolicitud << i + 1 << ". " << seleccionados[i] << "\n";
    }
    archivoSolicitud << "----------------------------------\n";

    archivoSolicitud.close();
    std::cout << "Su solicitud ha sido registrada correctamente.\nPresione Enter para volver...\n";
    std::cin.ignore();
    std::cin.get();
}
