#include "curso.hpp"
#include "estudiante.hpp"

Curso::Curso(std::string nombre) {
    c_nombre = nombre;
}
// La copia de Curso es deep copy a nivel curso, ya que estoy duplicando el vector de estudiantes,
// por lo que no estoy referenciando al mismo vector. Pero simultaneamente es una shallow copy del
// vector estudiantes, porque ambos vectores contienen los mismos pointers a los mismos estudiantes. 
Curso::Curso(const Curso& curso_a_copiar, std::string nombre) {
    c_nombre = nombre;
    c_estudiantes = std::vector<std::shared_ptr<Estudiante>>(curso_a_copiar.c_estudiantes);
    for (auto e : c_estudiantes) {
        e->agregar_curso(c_nombre, -1);
    }
}

void Curso::inscribir_estudiante(std::shared_ptr<Estudiante> estudiante, int nota){
    if (this->curso_completo()) {
        throw std::runtime_error("Curso completo, no se pueden añadir estudiantes");
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
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->get_legajo() == legajo){
            auto estudiante = *e;
            estudiante->eliminar_curso(c_nombre);
            e = c_estudiantes.erase(e);
            break;
        } else {
            ++e;
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

std::string Curso::get_nombre() const {
    return c_nombre;
}

void Curso::set_nombre(std::string nuevo_nombre){
    c_nombre = nuevo_nombre;
}

std::ostream& operator<<(std::ostream& os, const Curso& curso) {
    return os << curso.get_nombre();
}

void Curso::mostrar_estudiantes() const{
    // Ordena el vector de estudiantes. Usa una funcion lambda como comparador que -
    // dereferencia el iterador y el shared_ptr<Estudiante> y usa el operador sobrecargado < de estudiante.
    auto estudiantes_copia = c_estudiantes; // Copia para evitar problemas con el vector al ordenarlo.
    std::sort(estudiantes_copia.begin(), estudiantes_copia.end(), 
        [](const std::shared_ptr<Estudiante>& a, const std::shared_ptr<Estudiante>& b) -> bool {
            return *a < *b;
        });

    std::cout << "Estudiantes de " << this->c_nombre << ":" << std::endl;

    for (const auto& e : estudiantes_copia){
        std::cout << "-" << (*e.get()) << std::endl;
    }
}