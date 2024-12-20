#ifndef PLANALUMNO_H
#define PLANALUMNO_H

#include <string>
#include <vector>

class PlanAlumno {
private:
    std::string universidad;
    std::string facultad;
    std::string carrera;
    std::vector<std::pair<std::string, int>> asignaturas;
    std::string duracion;

public:
    PlanAlumno(const std::string& uni, const std::string& fac, const std::string& car,
               const std::vector<std::pair<std::string, int>>& asigs);

    void calcularDuracion();
    void mostrarResumenAlumno() const;
    void guardarEnArchivo(const std::string& rutaArchivo) const;
};

#endif

