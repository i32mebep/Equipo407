#ifndef CARRERA_H
#define CARRERA_H

#include <string>

class Carrera {
private:
    int id;
    std::string nombre;
    int idFacultad; // Relación con Facultad

public:
    Carrera(int id, const std::string& nombre, int idFacultad)
        : id(id), nombre(nombre), idFacultad(idFacultad) {}

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    int getIdFacultad() const { return idFacultad; }
};

#endif
