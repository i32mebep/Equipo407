#include "utilidades.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>  // Para std::cerr y manejo de salida estándar
#include <fstream>   // Para std::ifstream y manejo de archivos
#include <string>    // Para manejar std::string

// Implementación de obtenerFechaActual()
std::string obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(now, "%Y-%m-%d");
    return oss.str();
}

bool solicitudProfesorExistente(const std::string& dni) {
    std::ifstream archivo("../data/solicitud_profesor.dat");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de solicitudes de profesor.\n";
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("DNI: " + dni) != std::string::npos) {
            archivo.close();
            return true; // Solicitud existente
        }
    }

    archivo.close();
    return false; // No se encontró solicitud
}