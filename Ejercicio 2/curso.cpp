#include "curso.hpp"
#include "estudiante.hpp"

Curso::Curso(std::string nombre) {
    c_nombre = nombre;
}
// TODO Explicacion Deep copy de curso, shallow copy del vector:
Curso::Curso(const Curso& curso_a_copiar, std::string nombre) {
    c_nombre = nombre;
    c_estudiantes = std::vector<std::shared_ptr<Estudiante>>(curso_a_copiar.c_estudiantes);
    for (auto e : c_estudiantes) {
        e->agregar_curso(c_nombre, -1);
    }
}

void Curso::inscribir_estudiante(std::shared_ptr<Estudiante> estudiante, int nota){
    if (this->curso_completo()) {
        std::cerr << "Curso completo, no se pueden añadir estudiantes" << std::endl;
    }
    else if (esta_inscripto(estudiante->get_legajo())) {
        throw std::invalid_argument("El estudiante ya se encuentra inscripto.");
    }
    else {
        c_estudiantes.push_back(estudiante);
        estudiante->agregar_curso(c_nombre, nota);
    }
}

void Curso::desinscribir_estudiante(int legajo){
    // Se podria verificar si se encuentra inscripto, pero eso implicaria duplicar la cantidad de iteraciones.
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->get_legajo() == legajo){
            c_estudiantes.erase(e);
            (*e)->eliminar_curso(c_nombre);
            break;
        }
    }
}

bool Curso::esta_inscripto(int legajo) const{
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->get_legajo() == legajo){
            return true;
        }
    }
    return false;
}


bool Curso::curso_completo() const{
    return (c_estudiantes.size() == 20);
}

std::vector<std::shared_ptr<Estudiante>> Curso::get_estudiantes(){
    return c_estudiantes;
}

std::string Curso::get_nombre() const {
    return c_nombre;
}

void Curso::set_nombre(std::string nuevo_nombre){
    c_nombre = nuevo_nombre;
}

std::ostream& operator<<(std::ostream& os, const Curso& curso) {
    return os << curso.get_nombre();
}



void Curso::mostrar_estudiantes(){
    // Ordena el vector de estudiantes. Usa una funcion lambda como comparador que -
    // dereferencia el iterador y el shared_ptr<Estudiante> y usa el operador sobrecargado < de estudiante.
    std::sort(c_estudiantes.begin(), c_estudiantes.end(), 
        [](auto a, auto b)->bool{return (*a.get() < *b.get());});

    std::cout << "Estudiantes de " << this->c_nombre << ":" << std::endl;

    for (auto e : c_estudiantes){
        std::cout << "-" << (*e.get()) << std::endl;
    }
}