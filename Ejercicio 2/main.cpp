#include "estudiante.hpp"
#include "curso.hpp"

#include <iostream>

using namespace std;


int main(){
    std::shared_ptr<Curso> c = make_shared<Curso>("Matematica");

    std::shared_ptr<Estudiante> es = make_shared<Estudiante>("Emiliano", "Aguilera", 1175718);
    std::shared_ptr<Estudiante> es2 = make_shared<Estudiante>("Tomas", "Perez", 1175718);
    std::shared_ptr<Estudiante> es3 = make_shared<Estudiante>("Bautista", "Ceballos", 1175718);

    c->inscribir_estudiante(es, 9);
    c->inscribir_estudiante(es2, 10);
    c->inscribir_estudiante(es3, 8);

    es->mostrar_cursos();
    es2->mostrar_cursos();
    es3->mostrar_cursos();

    c->mostrar_estudiantes();
    std::cout<<std::endl;
}