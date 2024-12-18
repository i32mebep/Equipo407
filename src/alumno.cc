#include "alumno.h"
#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <sstream>

// Constructor de Alumno
Alumno::Alumno(const std::string& dni, const std::string& nombre, const std::string& email,
               const std::string& apellido1, const std::string& apellido2, const std::string& grado)
    : Usuario(dni, nombre, email, apellido1, apellido2), grado(grado) {}


// Función auxiliar para obtener la fecha actual
/*std::string obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    return std::string(buffer);
}
*/
// Función para verificar si el estudiante ya tiene una solicitud vigente
bool solicitudExistente(const std::string& dni) {
    std::ifstream archivo("../data/solicitud_estudiante.dat");
    if (!archivo) return false;

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("DNI: " + dni) != std::string::npos) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

// Método para solicitar inscripción
void Alumno::solicitarInscripcionAlumno() {
    std::string dni, nombre, carreraSeleccionada;
    std::vector<std::string> planesCompletos;
    int opcion;

    // Solicitar DNI y nombre del estudiante
    std::cout << "Introduzca su DNI: ";
    std::cin >> dni;

    std::cout << "Introduzca su nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    // Verificar si ya existe una solicitud
    if (solicitudExistente(dni)) {
    std::cout << "Ya tiene una solicitud vigente.\n";
    std::cout << "Presione Enter para continuar...\n";
    std::cin.ignore(); // Limpia el buffer
    std::cin.get();    // Espera a que el usuario presione Enter
    return;
    }

    // Mostrar carreras disponibles
    std::vector<std::string> carreras = {
        "Grado en Informatica",
        "Grado en Ingenieria Electronica",
        "Grado en Matematicas",
        "Grado en Fisica",
        "Grado en Quimica"
    };

    std::cout << "\nSeleccione su grado de entre las siguientes carreras:\n";
    for (size_t i = 0; i < carreras.size(); ++i) {
        std::cout << i + 1 << ". " << carreras[i] << "\n";
    }

    std::cout << "Opcion: ";
    std::cin >> opcion;

    if (opcion < 1 || opcion > (int)carreras.size()) {
        std::cout << "Opcion no valida. Operacion cancelada.\n";
        return;
    }

    carreraSeleccionada = carreras[opcion - 1];

    // Leer planes y filtrar por carrera seleccionada
    std::ifstream archivoPlanes("../data/planes_alumno.dat");
    if (!archivoPlanes) {
        std::cerr << "Error al abrir el archivo de planes.\n";
        return;
    }

    std::string linea, planCompleto;
    bool leerPlan = false;

    while (std::getline(archivoPlanes, linea)) {
        if (linea.find("Carrera: " + carreraSeleccionada) != std::string::npos) {
            leerPlan = true; // Inicia la captura de un plan
            planCompleto = linea + "\n";
        } else if (linea.find("--------------------------------------") != std::string::npos && leerPlan) {
            planCompleto += linea;
            planesCompletos.push_back(planCompleto); // Añade el plan completo
            leerPlan = false;
        } else if (leerPlan) {
            planCompleto += linea + "\n"; // Continúa capturando líneas del plan
        }
    }
    archivoPlanes.close();

    // Verificar si no hay planes disponibles
    if (planesCompletos.empty()) {
        std::cout << "\nNo hay planes de convalidacion disponibles para " << carreraSeleccionada << ".\n";
        std::cout << "Presione Enter para continuar...\n";
        std::cin.ignore();
        std::cin.get(); // Espera hasta que el usuario presione Enter
        return;
    }

    // Mostrar los planes completos
    std::cout << "\nPlanes de Convalidacion disponibles para " << carreraSeleccionada << ":\n";
    for (size_t i = 0; i < planesCompletos.size(); ++i) {
        std::cout << "Plan " << i + 1 << ":\n" << planesCompletos[i] << "\n";
    }

    // Seleccionar planes por orden de preferencia
    std::vector<std::string> planesOrdenados;
    while (true) {
        std::cout << "Seleccione el numero del plan por orden de preferencia (0 para terminar): ";
        std::cin >> opcion;
        if (opcion == 0) break;

        if (opcion > 0 && opcion <= (int)planesCompletos.size()) {
            planesOrdenados.push_back(planesCompletos[opcion - 1]);
            std::cout << "Plan agregado a su lista de preferencia.\n";
        } else {
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }

    if (planesOrdenados.empty()) {
        std::cout << "No ha seleccionado ningun plan.\n";
        return;
    }

    // Guardar la solicitud en el archivo
    std::ofstream archivoSolicitud("../data/solicitud_estudiante.dat", std::ios::app);
    if (!archivoSolicitud) {
        std::cerr << "Error al abrir el archivo de solicitudes.\n";
        return;
    }

    std::string fecha = obtenerFechaActual();
    archivoSolicitud << "DNI: " << dni << "\n";
    archivoSolicitud << "Nombre: " << nombre << "\n";
    archivoSolicitud << "Fecha: " << fecha << "\n";
    archivoSolicitud << "Estado: Pendiente\n";
    archivoSolicitud << "Planes seleccionados (Orden de preferencia):\n";

    for (size_t i = 0; i < planesOrdenados.size(); ++i) {
        archivoSolicitud << "Preferencia " << i + 1 << ":\n" << planesOrdenados[i];
    }

    archivoSolicitud << "--------------------------------------\n";
    archivoSolicitud.close();

    std::cout << "\nSu solicitud ha sido registrada correctamente.\n";
    std::cout << "Presione Enter para continuar...\n";
    std::cin.ignore();
    std::cin.get(); // Espera hasta que el usuario presione Enter
}