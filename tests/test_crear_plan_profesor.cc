#include "../src/administrador.h"
#include "../src/utilidades.h"
#include <iostream>
#include <cassert>

// Función para probar la creación de un plan para profesores
void testCrearPlanProfesor() {
    Administrador admin("22222222D", "Admin2", "admin2@example.com", "Admin", "Test2");

    // Crear un plan para profesores
    admin.crearPlanConvalidacionProfesor();

    // Verificar que el plan se haya registrado en el fichero
    std::ifstream archivo("../data/planes_profesor.dat");
    assert(archivo && "El archivo de planes de profesor no se pudo abrir");

    std::string linea;
    bool planEncontrado = false;
    while (std::getline(archivo, linea)) {
        if (linea.find("Departamento:") != std::string::npos) {
            planEncontrado = true;
            break;
        }
    }
    archivo.close();

    assert(planEncontrado && "El plan para profesores no se registró correctamente");

    std::cout << "Test de creación de plan para profesores: PASADO\n";
}

int main() {
    testCrearPlanProfesor();
    return 0;
}
