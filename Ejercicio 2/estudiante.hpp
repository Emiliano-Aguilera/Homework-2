#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <iomanip> // setprecision

class Curso;

class Estudiante{
    private:
        std::string e_nombre;
        std::string e_apellido;
        // Legajo del estudiante, no se checkea que sea unico.
        int e_legajo;
        // Vector que contiene pairs que constan de nombre del curso y su nota
        std::vector<std::pair<std::string, int>> e_notas;
    public:
        //Constructor, toma un nombre un apellido y un legajo.
        Estudiante(std::string nombre, std::string apellido, int legajo);

        // Sobrecarga operador <, compara los nombres de los estudiantes y devuelve true si el de la derecha es mayor
        bool operator<(const Estudiante& otroEstudiante) const;
        // Sobrecarga operador <<, ingresa el nombre y apellido del estudiante a un ostream, para poder usarlo con cout
        friend std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante);

        // Devuelve el legajo
        int get_legajo() const;
        // Calcula el promedio de notas, si no hay cursos, devuelve -1.0
        float get_promedio() const;
        // Modifica la nota asociada a un curso.
        void mod_nota(std::string nombreCurso, float nota);
        // Agrega un curso, usa un puntero a curso para poder usar std::pair
        void agregar_curso(std::string nombreCurso, int nota);
        // Elimina un curso, usa un puntero a curso.
        void eliminar_curso(std::string nombreCurso);
        
        // Devuelve solo el nombre
        std::string get_nombre() const;
        // Devuelve solo el apellido
        std::string get_apellido() const;
        // Concatena nombre y apellido, los devuelve como una sola string
        std::string get_nombre_completo() const;
};