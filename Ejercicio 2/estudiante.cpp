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
    std::string nombre1 = this->getNombre();
    std::string nombre2 = otroEstudiante.getNombre();
    
    return nombre1.at(0) < nombre2.at(0);
}

std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante){
    os << estudiante.getNombreCompleto();
    return os;
}

// Metodos publicos
int Estudiante::getLegajo() const{
    return e_legajo;
}

float Estudiante::getPromedio() const{
    int cant_cursos = e_notas.size();
    int suma = 0;

    for (auto par : e_notas){
        suma += par.second;
        std::cout << suma << par.second << std::endl;
    }

    return (cant_cursos > 0) ? suma / cant_cursos : -1.0;
}

void Estudiante::agregarCurso(Curso* curso, int nota){
    std::pair<Curso*, int> par_curso_nota(curso, nota);
    e_notas.push_back(par_curso_nota);
}

void Estudiante::eliminarCurso(Curso* curso){
    for (auto c = e_notas.begin(); c != e_notas.end(); c++) {
        // compara los pointers al curso, dereferenciando el shared_ptr
        if (c->first == curso) {
            e_notas.erase(c);
            break;
        }
    }
}

std::string Estudiante::getNombre() const{
    return e_nombre;
}

std::string Estudiante::getApellido() const{
    return e_apellido;
}

std::string Estudiante::getNombreCompleto() const{
    std::string nombreCompleto = e_nombre + ' ' + e_apellido;
    return nombreCompleto;
}


//Funcion Helper BORRAR
void Estudiante::mostrarCursos() const{
    if (e_notas.empty()){
        std::cout << "No hay cursos" << std::endl;
    }
    else {
        std::cout << "Cursos de " << this->getNombreCompleto() << ":" << std::endl;
        for(auto c : e_notas){
            std::cout << c.first->getNombre() << std::endl;
        }   
        std::cout << "Promedio: " << this->getPromedio() <<std::endl << std::endl;
    }
}