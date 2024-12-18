#ifndef ALUMNO_H
#define ALUMNO_H

#include "usuario.h"
#include <string>

class Alumno : public Usuario {
private:
    std::string grado;

public:
    Alumno(const std::string& dni, const std::string& nombre, const std::string& email,
           const std::string& apellido1, const std::string& apellido2, const std::string& grado);

    void solicitarInscripcionAlumno(); // Método para solicitar inscripción
};

#endif
