#include "curso.hpp"
#include "estudiante.hpp"

#include <iostream>

using namespace std;

// Pregunta c: La relacion entre ambos es de agregacion-asociacion, ya que curso contiene estudiantes, (el todo)
// Y estudiantes contiene cursos, pero la existencia de ambos es independiente, los estudiantes existen a pesar
// de que no existan cursos y viceversa.

int main(){
    shared_ptr<Curso> matematica = make_shared<Curso>("Matematica");

    shared_ptr<Estudiante> est1 = make_shared<Estudiante>("Azmiliano", "Aguilera", 10);
    matematica->inscribir_estudiante(est1, 10);

    shared_ptr<Estudiante> est2 = make_shared<Estudiante>("Aban", "Perez", 20);
    matematica->inscribir_estudiante(est2, 8);

    shared_ptr<Estudiante> est3 = make_shared<Estudiante>("Aaa", "Gonzalez", 30);
    matematica->inscribir_estudiante(est3, 3);

    shared_ptr<Estudiante> est4 = make_shared<Estudiante>("Axexei", "Ivanovich", 40);
    matematica->inscribir_estudiante(est4, 9);

    est1->mostrar_cursos();
    est2->mostrar_cursos();
    est3->mostrar_cursos();
    est4->mostrar_cursos();

    shared_ptr<Curso> lengua = make_shared<Curso>(*matematica.get(), "Lengua");
    lengua->inscribir_estudiantes_copy();

    matematica->mostrar_estudiantes();
    cout<<endl;
    lengua->mostrar_estudiantes();

    cout<<endl;
    est1->mostrar_cursos();
    est2->mostrar_cursos();
    est3->mostrar_cursos();
    est4->mostrar_cursos();
}