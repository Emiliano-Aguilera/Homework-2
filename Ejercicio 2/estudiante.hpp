#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Forward declaration
class Curso;

class Estudiante{
    private:
        // Atributos
        std::string e_nombre;
        std::string e_apellido;
        int e_legajo;

        std::vector<std::pair<Curso*, int>> e_notas;
    public:
        //Constructor
        Estudiante(std::string nombre, std::string apellido, int legajo);

        // Sobrecarga de operadores
        bool operator<(const Estudiante& otroEstudiante) const;
        friend std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante);

        // Metodos publicos
        int getLegajo() const;
        float getPromedio() const;
        void agregarCurso(Curso* curso, int nota);
        void eliminarCurso(Curso* curso);
        
        std::string getNombre() const;
        std::string getApellido() const;
        std::string getNombreCompleto() const;

        // helper functions BORRAR
        void mostrarCursos() const;
};