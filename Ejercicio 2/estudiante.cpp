#include "estudiante.hpp"
#include "curso.hpp"


// Constructor
Estudiante::Estudiante(std::string nombre, std::string apellido, int legajo){
    e_nombre = nombre;
    e_apellido = apellido;
    e_legajo = legajo;
}


// Sobrecarga de operadores
bool Estudiante::operator<(const Estudiante& otroEstudiante) const{
    std::string nombre1 = this->get_nombre();
    std::string nombre2 = otroEstudiante.get_nombre();
    
    return nombre1 < nombre2;
}

std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante){
    return (os << estudiante.get_nombre_completo());
}


// Metodos publicos
int Estudiante::get_legajo() const{
    return e_legajo;
}

void Estudiante::mod_nota(std::string nombreCurso, float nota){
    for (auto i = e_notas.begin(); i != e_notas.end(); i++) {
        if (i->first == nombreCurso) {
            i->second = nota;
            break;
        } 
    }
}

float Estudiante::get_promedio() const{
    int cant_cursos = 0;
    float suma = 0;

    // Solo suma los cursos que tienen una nota.
    for (auto par : e_notas){
        if (par.second >= 0) {
            suma += par.second;
            cant_cursos++;
        }
    }

    // Devuelve el promedio siempre y cuando haya al menos un curso, ya que sino haria division por cero.
    return (cant_cursos > 0) ? (suma / cant_cursos) : -1.0;
}

void Estudiante::agregar_curso(std::string nombreCurso, int nota){
    std::pair<std::string, int> par_curso_nota(nombreCurso, nota);
    e_notas.push_back(par_curso_nota);
}

void Estudiante::eliminar_curso(std::string nombreCurso) {
    for (auto i = e_notas.begin(); i != e_notas.end(); ) {
        if (i->first == nombreCurso) {
            i = e_notas.erase(i);
        } 
        else {
            ++i;
        }
    }
}

std::string Estudiante::get_nombre() const{
    return e_nombre;
}

std::string Estudiante::get_apellido() const{
    return e_apellido;
}

std::string Estudiante::get_nombre_completo() const{
    std::string nombreCompleto = e_nombre + ' ' + e_apellido;
    return nombreCompleto;
}