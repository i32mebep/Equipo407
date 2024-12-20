#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"
#include <string>

class Administrador : public Usuario {
public:
    Administrador(const std::string& dni, const std::string& nombre, const std::string& email,
                  const std::string& apellido1, const std::string& apellido2);

    void crearPlanDeConvalidacion(); // Submenú para elegir tipo de plan
    void crearPlanDeConvalidacionAlumno(); // Crear plan para alumnos
    void crearPlanDeConvalidacionProfesor(); // Crear plan para profesores
};

#endif
