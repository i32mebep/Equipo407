#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "administrador.h"
#include "alumno.h"
#include "profesor.h"
#include "planConvalidacion.h"
#include "planAlumno.h"

void mostrarMenuAdministrador();
void mostrarMenuProfesor();
void mostrarMenuAlumno();

void limpiarPantalla() {
    system("clear"); 
}

int main() {
    int rolSeleccionado;

    do {
        limpiarPantalla();
        std::cout << "===== Sistema de Gestion SICUE =====" << std::endl;
        std::cout << "Seleccione su rol:\n";
        std::cout << "1. Administrador\n";
        std::cout << "2. Profesor\n";
        std::cout << "3. Alumno\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> rolSeleccionado;

        switch (rolSeleccionado) {
            case 1:
                mostrarMenuAdministrador();
                break;
            case 2:
                mostrarMenuProfesor();
                break;
            case 3:
                mostrarMenuAlumno();
                break;
            case 0:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (rolSeleccionado != 0);

    return 0;
}

void mostrarMenuAdministrador() {
    int opcion;
    Administrador admin("", "", "", "", ""); // Administrador vacío
    do {
        limpiarPantalla();
        std::cout << "\n=== Menu Administrador ===\n";
        std::cout << "1. Crear Plan de Convalidacion\n";
        std::cout << "2. Ver Historial de Solicitudes (No implementado)\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada invalida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                admin.crearPlanDeConvalidacion(); // Llamada al submenú en administrador.cc
                break;
            case 2:
                std::cout << "Esta funcionalidad no esta implementada.\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void mostrarMenuProfesor() {
    int opcion;
    Profesor profesor("", "", "", "", "", "");
    do {
        limpiarPantalla();
        std::cout << "\n=== Menu Profesor ===\n";
        std::cout << "1. Solicitar Inscripcion\n";
        std::cout << "2. Ver Solicitudes (No implementado)\n";
        std::cout << "3. Anular Solicitud (No implementado)\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cout << std::endl;

        if (std::cin.fail()) {  // Detecta una entrada no válida
            std::cin.clear();   // Limpia el estado de error
            std::cin.ignore(1000, '\n'); // Descarta los caracteres restantes
            std::cout << "Entrada invalida. Por favor, introduzca un numero.\n\n";
            continue;
        }

        switch (opcion) {
            case 1:
                std::cout << "Solicitando Inscripcion (Seleccionar Plan de Convalidacion)...\n";
                profesor.solicitarInscripcionProfesor();
                break;
            case 2:
            case 3:
                std::cout << "Esta funcionalidad no esta implementada.\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

void mostrarMenuAlumno() {

    Alumno alumno("", "", "", "", "", "");

    int opcion;
    do {
        limpiarPantalla();
        std::cout << "\n=== Menu Alumno ===\n";
        std::cout << "1. Solicitar Inscripcion\n";
        std::cout << "2. Ver Solicitudes (No implementado)\n";
        std::cout << "3. Anular Solicitud (No implementado)\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cout << std::endl;

        if (std::cin.fail()) {  // Detecta una entrada no válida
            std::cin.clear();   // Limpia el estado de error
            std::cin.ignore(1000, '\n'); // Descarta los caracteres restantes
            std::cout << "Entrada invalida. Por favor, introduzca un numero.\n\n";
            continue;
        }

        switch (opcion) {
            case 1:
                std::cout << "Solicitando Inscripcion (Seleccionar Plan de Convalidacion)...\n";
                alumno.solicitarInscripcionAlumno();
                break;
            case 2:
            case 3:
                std::cout << "Esta funcionalidad no esta implementada.\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}
