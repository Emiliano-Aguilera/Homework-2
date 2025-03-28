#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>

class Estudiante;

class Curso{
    private:
        std::string c_nombre;
        std::vector<Estudiante*> c_estudiantes;
    public:
        Curso(std::string nombre);

        // Metodos
        void inscribirEstudiante(Estudiante* estudiante, int nota);
        void desinscribirEstudiante(int legajo);
        bool estaInscripto(int legajo) const;
        bool cursoCompleto() const;
        void mostrarEstudiantes() const;
        std::string getNombre() const;
};