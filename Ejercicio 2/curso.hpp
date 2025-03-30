#pragma once

#include <iostream> // cout
#include <vector> // vector
#include <algorithm> // std::sort()
#include <memory> // shared_ptr
#include <string> // string

class Estudiante;

class Curso :public std::enable_shared_from_this<Curso> {
    private:
        std::string c_nombre;
        std::vector<std::shared_ptr<Estudiante>> c_estudiantes;
    public:
        // Constructor
        Curso(std::string nombre);

        // Metodos
        // Toma un pointer a estudiante y la nota del curso, para poder insertar el curso en el estudiante
        void inscribir_estudiante(std::shared_ptr<Estudiante> estudiante, int nota);
        // En base a un legajo, desinscribe al primer estudiante con ese legajo. Se asume que el legajo es unico.
        void desinscribir_estudiante(int legajo);
        // Devuelve true si el estudiante con ese legajo esta inscripto
        bool esta_inscripto(int legajo) const;
        // Devuelve true si el curso tiene 20 estudiantes
        bool curso_completo() const;
        // Imprime los estudiantes en orden alfabetico segun su nombre.
        void mostrar_estudiantes();
        // Devuelve solo el nombre del curso
        std::string get_nombre() const;
        // Devulve el vector de shared ptr a estudiante
        std::vector<std::shared_ptr<Estudiante>> get_estudiantes();
        // Cambia el nombre del curso
        void set_nombre(std::string nuevo_nombre);
};