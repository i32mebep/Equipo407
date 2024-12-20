#include "../src/alumno.h"
#include "../src/utilidades.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>

void testInscripcionDuplicadaAlumno() {
    // Limpia el archivo de solicitudes antes del test
    std::ofstream limpiar("../data/solicitud_estudiante.dat", std::ios::trunc);
    limpiar.close();

    // Crear instancia de Alumno
    Alumno alumno("12345678A", "Juan", "juan@gmail.com", "Gonzalez", "Lopez", "Grado en Informática");

    std::cout << "=== Test de Inscripción Duplicada de Alumno ===\n\n";

    // Mostrar información del alumno utilizado en el test
    std::cout << "Información del Alumno:\n";
    std::cout << "DNI: " << alumno.getDni() << "\n";
    std::cout << "Nombre: " << alumno.getNombre() << "\n\n";

    // Simular la primera inscripción
    std::cout << "Simulando la primera inscripción...\n";
    std::istringstream input1("12345678A\nJuan\n1\n1\n0\n"); // DNI, Nombre, Grado (Opción 1), Plan (Opción 1), Finalizar
    std::cin.rdbuf(input1.rdbuf());
    alumno.solicitarInscripcionAlumno("../data/planes_alumno.dat", "../data/solicitud_estudiante.dat");
    std::cout << "Primera inscripción completada.\n\n";

    // Verificar que se registró la primera inscripción
    std::ifstream archivoSolicitud("../data/solicitud_estudiante.dat");
    assert(archivoSolicitud && "No se pudo abrir el archivo de solicitudes para la verificación.");
    int count = 0;
    std::string linea;
    while (std::getline(archivoSolicitud, linea)) {
        if (linea.find("DNI: " + alumno.getDni()) != std::string::npos) {
            count++;
        }
    }
    archivoSolicitud.close();
    assert(count == 1 && "La primera inscripción no se registró correctamente.");

    // Simular una inscripción duplicada
    std::cout << "Intentando inscripción duplicada con el mismo DNI...\n";
    std::istringstream input2("12345678A\nJuan\n1\n1\n0\n"); // Mismos datos del alumno
    std::cin.rdbuf(input2.rdbuf());
    alumno.solicitarInscripcionAlumno("../data/planes_alumno.dat", "../data/solicitud_estudiante.dat");

    // Verificar que no se registró una inscripción duplicada
    archivoSolicitud.open("../data/solicitud_estudiante.dat");
    count = 0;
    while (std::getline(archivoSolicitud, linea)) {
        if (linea.find("DNI: " + alumno.getDni()) != std::string::npos) {
            count++;
        }
    }
    archivoSolicitud.close();
    assert(count == 1 && "El sistema permitió una inscripción duplicada.");

    // Mensaje final de éxito
    std::cout << "Resultado del Test: PASADO\n";
    std::cout << "==========================================\n";
}

int main() {
    testInscripcionDuplicadaAlumno();
    return 0;
}