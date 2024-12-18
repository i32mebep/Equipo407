#include "planProfesor.h"
#include <fstream>

// Constructor
PlanProfesor::PlanProfesor(const std::string& universidad, const std::string& facultad,
                           const std::string& departamento, const std::string& duracion)
    : universidad(universidad), facultad(facultad), departamento(departamento), duracion(duracion) {}

// Método para mostrar el resumen del plan
void PlanProfesor::mostrarResumenProfesor() const {
    std::cout << "\n=== Resumen del Plan de Convalidacion ===\n";
    std::cout << "Universidad: " << universidad << "\n";
    std::cout << "Facultad: " << facultad << "\n";
    std::cout << "Departamento: " << departamento << "\n";
    std::cout << "Duracion: " << duracion << "\n";
}

// Método para guardar en un archivo
void PlanProfesor::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo, std::ios::app); // Modo de añadir
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar el plan de profesor.\n";
        return;
    }

    // Escribir los datos en el formato especificado
    archivo << "Departamento: " << departamento << "\n";
    archivo << "Universidad: " << universidad << "\n";
    archivo << "Duracion: " << duracion << "\n";
    archivo << "----------------------------------\n"; // Separador entre planes

    archivo.close();
}
