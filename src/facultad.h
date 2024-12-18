#ifndef FACULTAD_H
#define FACULTAD_H

#include <string>

class Facultad {
private:
    int id;
    std::string nombre;
    int idUniversidad; // Relación con Universidad

public:
    Facultad(int id, const std::string& nombre, int idUniversidad)
        : id(id), nombre(nombre), idUniversidad(idUniversidad) {}

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    int getIdUniversidad() const { return idUniversidad; }
};

#endif