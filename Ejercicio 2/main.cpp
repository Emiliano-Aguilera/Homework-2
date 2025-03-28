#include "estudiante.hpp"
#include "curso.hpp"

#include <iostream>

using namespace std;


int main(){
    Curso c{"Mate1"};
    Curso c2{"Mate2"};
    Curso c3{"Mate3"};

    Estudiante es("z", "A", 1175718);
    Estudiante es2("a", "B", 1175718);
    Estudiante es3("m", "C", 1175718);

    c.inscribirEstudiante(&es2, 8);
    c.inscribirEstudiante(&es3, 5);

    c2.inscribirEstudiante(&es3, 10);
    c2.inscribirEstudiante(&es, 10);

    c3.inscribirEstudiante(&es, 9); 
    c3.inscribirEstudiante(&es2, 4);

    es.mostrarCursos();
    es2.mostrarCursos();
    es3.mostrarCursos();

    c.mostrarEstudiantes();
    c2.mostrarEstudiantes();
    c3.mostrarEstudiantes();
}