#include "planAlumno.h"
#include <iostream>
#include <fstream>

PlanAlumno::PlanAlumno(const std::string& uni, const std::string& fac, const std::string& car,
                       const std::vector<std::pair<std::string, int>>& asigs)
    : universidad(uni), facultad(fac), carrera(car), asignaturas(asigs) {
    calcularDuracion();
}

void PlanAlumno::calcularDuracion() {
    duracion = (asignaturas.size() <= 5) ? "Cuatrimestre" : "Año completo";
}

void PlanAlumno::mostrarResumenAlumno() const {
    std::cout << "\n=== Resumen del Plan de Convalidación ===\n";
    std::cout << "Universidad: " << universidad << "\n";
    std::cout << "Facultad: " << facultad << "\n";
    std::cout << "Carrera: " << carrera << "\n";
    std::cout << "Duracion: " << duracion << "\n";
    std::cout << "Asignaturas:\n";
    for (const auto& asig : asignaturas) {
        std::cout << "- " << asig.first << " (" << asig.second << " creditos)\n";
    }
}

void PlanAlumno::guardarEnArchivo(const std::string& rutaArchivo) const{
    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar el plan de convalidación.\n";
        return;
    }

    archivo << "Carrera: " << carrera << "\n";
    archivo << "Universidad: " << universidad << "\n";
    archivo << "Facultad: " << facultad << "\n";
    archivo << "Duracion: " << duracion << "\n";
    archivo << "Asignaturas:\n";

    for (const auto& asig : asignaturas) {
        archivo << "- " << asig.first << " (" << asig.second << " creditos)\n";
    }
    archivo << "--------------------------------------\n";

    archivo.close();
}


/*
void PlanAlumno::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo, std::ios::app);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar el plan.\n";
        return;
    }

    archivo << "Universidad: " << universidad << "\n";
    archivo << "Facultad: " << facultad << "\n";
    archivo << "Carrera: " << carrera << "\n";
    archivo << "Duracion: " << duracion << "\n";
    archivo << "Asignaturas:\n";

    for (const auto& asig : asignaturas) {
        archivo << "- " << asig.first << " (" << asig.second << " creditos)\n";
    }
    archivo << "--------------------------------------\n";

    archivo.close();

    */
