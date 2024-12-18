#ifndef PLANCONVALIDACION_H
#define PLANCONVALIDACION_H

#include <vector>
#include <string>

class PlanConvalidacion {
private:
    std::string universidad;
    std::string facultad;
    std::string carrera;
    std::vector<std::string> asignaturas;

public:
    PlanConvalidacion(const std::string& universidad, const std::string& facultad,
                      const std::string& carrera, const std::vector<std::string>& asignaturas)
        : universidad(universidad), facultad(facultad), carrera(carrera), asignaturas(asignaturas) {}

    void mostrarResumen() const {
        std::cout << "Universidad: " << universidad << "\n"
                  << "Facultad: " << facultad << "\n"
                  << "Carrera: " << carrera << "\n"
                  << "Asignaturas: ";
        for (const auto& asignatura : asignaturas) {
            std::cout << asignatura << ", ";
        }
        std::cout << "\n";
    }
};

#endif
