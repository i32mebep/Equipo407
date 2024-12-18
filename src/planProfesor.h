#ifndef PLANPROFESOR_H
#define PLANPROFESOR_H

#include <string> // Importante incluir esto
#include <iostream>

class PlanProfesor {
private:
    std::string universidad;
    std::string facultad;
    std::string departamento;
    std::string duracion; // Cuatrimestre o Año

public:
    PlanProfesor(const std::string& universidad, const std::string& facultad,
                 const std::string& departamento, const std::string& duracion);

    void mostrarResumenProfesor() const;
    void guardarEnArchivo(const std::string& rutaArchivo) const; // Coincide con el .cc
};

#endif  