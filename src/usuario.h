#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string dni;
    std::string nombre;
    std::string email;
    std::string apellido1;
    std::string apellido2;

public:
    Usuario(const std::string& dni, const std::string& nombre, const std::string& email,
            const std::string& apellido1, const std::string& apellido2)
        : dni(dni), nombre(nombre), email(email), apellido1(apellido1), apellido2(apellido2) {}

    // Getters
    std::string getDni() const { return dni; }
    std::string getNombre() const { return nombre; }
};

#endif
