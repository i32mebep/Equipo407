#include "../src/alumno.h"
#include "../src/utilidades.h"
#include <iostream>
#include <cassert>
#include <fstream>


void testInscripcionAlumno() {
    // Simula la inscripción de un estudiante
    std::string ficheroPlanes = "../data/planes_alumno.dat";
    std::string ficheroSolicitud = "../data/solicitud_estudiante.dat";

    // Crea un alumno y ejecuta la función de inscripción
    Alumno alumno("4567890", "piedra", "piedra@email.com", "Apellido1", "Apellido2", "Grado en Informática");
    alumno.solicitarInscripcionAlumno(ficheroPlanes, ficheroSolicitud);

    // Verifica si la solicitud se registró correctamente
    std::ifstream archivo(ficheroSolicitud);
    assert(archivo.is_open() && "No se pudo abrir el archivo de solicitudes para verificar.");

    std::string linea;
    bool solicitudEncontrada = false;

    // Itera sobre las líneas del archivo para buscar la solicitud
    while (std::getline(archivo, linea)) {
        // Busca un patrón único que identifique la solicitud del estudiante
        if (linea.find("DNI: 4567890") != std::string::npos) {
            solicitudEncontrada = true;
            break;
        }
    }
    archivo.close();

    // Verifica que se encontró la solicitud
    assert(solicitudEncontrada && "La solicitud del estudiante no se registró correctamente");
    std::cout << "El test de inscripción del alumno pasó correctamente.\n";
}

int main() {
    testInscripcionAlumno();
    return 0;
}
