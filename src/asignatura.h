#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>

class Asignatura {
private:
    std::string nombre;
    int codigo;
    int creditos;

public:
    Asignatura(const std::string& nombre, int codigo, int creditos);
};

#endif
