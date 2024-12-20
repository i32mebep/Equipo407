#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <string>

class Universidad {
private:
    int id;
    std::string nombre;

public:
    Universidad(int id, const std::string& nombre) : id(id), nombre(nombre) {}

    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
};

#endif