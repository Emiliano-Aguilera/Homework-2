#include "curso.hpp"
#include "estudiante.hpp"

Curso::Curso(std::string nombre) {
    c_nombre = nombre;
}
// Explicacion: El copy constructor en este caso tiene que copiar los estudiantes inscriptos, y luego inscribir todos los estudiantes a este nuevo curso, 
// No podemos simplemente copiar el vector de estudiantes porque los estudiantes no tendrian a este nuevo curso dentro de ellos. Ademas de que si desinscribimos
// a un estudiante de el curso original, tambien se eliminaria de el vector de este nuevo curso. Por lo que debemos duplicar el vector c_estudiantes e iterar
// sobre todos los estudiantes para añadir el nuevo curso a cada estudiante. Manteniendo que todos apunten al mismo objeto y que los cursos apuntan a los mismos
// estudiantes.
Curso::Curso(Curso& curso_a_copiar, std::string nombre) : std::enable_shared_from_this<Curso>() {
    c_nombre = nombre;
    c_estudiantes = std::vector<std::shared_ptr<Estudiante>>(curso_a_copiar.c_estudiantes);
}

void Curso::inscribir_estudiantes_copy(){
    for(auto e : c_estudiantes){
        e->agregar_curso(weak_from_this(), -1);
    }
}

void Curso::inscribir_estudiante(std::shared_ptr<Estudiante> estudiante, int nota){
    if (this->curso_completo()){
        std::cerr << "Curso completo, no se pueden añadir estudiantes" << std::endl;
    }
    else {
        c_estudiantes.push_back(estudiante);
        estudiante->agregar_curso(weak_from_this(), nota);
    }
}

void Curso::desinscribir_estudiante(int legajo){
    for (auto e = c_estudiantes.begin(); e != c_estudiantes.end(); e++) {
        if ((*e)->get_legajo() == legajo){
            c_estudiantes.erase(e);
            (*e)->eliminar_curso(shared_from_this());
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


std::string Curso::get_nombre() const {
    return c_nombre;
}

std::vector<std::shared_ptr<Estudiante>> Curso::get_estudiantes(){
    return c_estudiantes;
}

void Curso::set_nombre(std::string nuevo_nombre){
    c_nombre = nuevo_nombre;
}


void Curso::mostrar_estudiantes(){
    // Ordena el vector de estudiantes. Usa una funcion lambda como comparador que -
    // dereferencia el iterador y el shared_ptr<Estudiante> y usa el operador sobrecargado < de estudiante.
    std::sort(c_estudiantes.begin(), c_estudiantes.end(), 
        [](auto a, auto b)->bool{return (*a.get() < *b.get());});

    std::cout << "Estudiantes de " << this->c_nombre << ":" << std::endl;

    for (auto e : c_estudiantes){
        std::cout << (*e.get()) << std::endl;
    }
}