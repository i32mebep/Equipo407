#ifndef PROFESOR_H
#define PROFESOR_H

#include "usuario.h"
#include <string>

class Profesor : public Usuario {
private:
    std::string departamento;

public:
    Profesor(const std::string& dni, const std::string& nombre, const std::string& apellido1,
             const std::string& apellido2, const std::string& email, const std::string& departamento);

    void solicitarInscripcionProfesor();
    void crearPlanConvalidacionProfesor();
};

#endif