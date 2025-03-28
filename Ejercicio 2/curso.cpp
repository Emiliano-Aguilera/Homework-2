#include "curso.hpp"
#include "estudiante.hpp"

Curso::Curso(std::string nombre) {
    c_nombre = nombre;
}

void Curso::inscribirEstudiante(Estudiante* estudiante, int nota){
    if (this->cursoCompleto()){
        throw std::runtime_error("Curso completo, no se puede inscribir.");
    }
    else {
        c_estudiantes.push_back(estudiante);
        estudiante->agregarCurso(this, nota);
    }
}

void Curso::desinscribirEstudiante(int legajo){
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->getLegajo() == legajo){
            c_estudiantes.erase(e);
            (*e)->eliminarCurso(this);
            break;
        }
    }
}

bool Curso::estaInscripto(int legajo) const{
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->getLegajo() == legajo){
            return true;
        }
    }
    return false;
}

bool Curso::cursoCompleto() const{
    return (c_estudiantes.size() == 20);
}

std::string Curso::getNombre() const {
    return c_nombre;
}

void Curso::mostrarEstudiantes() const{
    // Deberia hacer una copia? para poder hacer que mostrar estudiantes sea const?
    std::vector<Estudiante> estudiantes;

    for (const auto& e : c_estudiantes) {
        estudiantes.push_back(*e);
    }

    std::sort(estudiantes.begin(), estudiantes.end());

    std::cout << "Estudiantes de " << this->c_nombre << ":" << std::endl;
    for (auto e : estudiantes){
        std::cout << e << std::endl;
    }
}