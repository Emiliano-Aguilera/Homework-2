#include "curso.hpp"
#include "estudiante.hpp"

#include <iostream>
#include <limits>

using namespace std;

u_int getUint();
u_int getUint(u_int range);

// Muestra el mensaje de bienvenida
void mensajeInicial(vector<shared_ptr<Curso>> cursos, vector<shared_ptr<Estudiante>> estudiantes);
void ignoreLine();


// Pregunta c: La relacion entre ambos es de agregacion, ya que curso contiene estudiantes, (el todo)
// pero la existencia de ambos es independiente, los estudiantes existen a pesar
// de que no existan cursos y viceversa.

int main(){
    vector<shared_ptr<Curso>> cursos
    {
        make_shared<Curso>("Matematica"),
        make_shared<Curso>("Lengua")
    };

    vector<shared_ptr<Estudiante>> estudiantes
    {
        make_shared<Estudiante>("Emiliano", "Aguilera", 0000),
        make_shared<Estudiante>("Tomas", "Perez", 0001)
    };

    // Estudiante 0 inicia inscripto en matematica.
    cursos.at(0)->inscribir_estudiante(estudiantes.at(0), 9);
    // Estudiante 1 inicia inscripto en Langua.
    cursos.at(1)->inscribir_estudiante(estudiantes.at(1), 6);

    cout << "Bienvenido al ejercicio 2 del Homework 2" << endl;

    u_int accion;
    do{
        mensajeInicial(cursos, estudiantes);

        // Tomar u_int
        cout << "Eleccion: ";
        accion = getUint();

        // Actuar en consecuencia
        switch (accion){
            case 1:
            {
                cout << "Check inscripcion y desincripcion de estudiantes." << endl << endl;
                cout << "Inscribiendo a " << *estudiantes.at(1) << " en el curso " << *cursos.at(0) << "..." << endl;
                cursos.at(0)->inscribir_estudiante(estudiantes.at(1), 6);

                cursos.at(0)->mostrar_estudiantes();

                cout << endl;

                cout << "Desinscribiendo a " << *estudiantes.at(1) << " del curso " << *cursos.at(0) << "..." << endl;
                cursos.at(0)->desinscribir_estudiante(estudiantes.at(1)->get_legajo());

                cursos.at(0)->mostrar_estudiantes();
                break;
            }
            case 2:
            {
                cout << "Check inscripcion de estudiante." << endl << endl;

                // Primero se muestran los estudiantes inscriptos a cada curso, para poder verificar.
                cursos.at(0)->mostrar_estudiantes();
                cout << endl;
                cursos.at(1)->mostrar_estudiantes();
                cout << endl;

                cout << "Test: Legajo 1 (Tomas Perez) esta inscripto en lengua y en matematica:" << endl;

                cout << "* Resultado inscripcion en Lengua: " << boolalpha << cursos.at(1)->esta_inscripto(1) << endl;
                cout << "* Resultado inscripcion en Matematica: " << boolalpha << cursos.at(0)->esta_inscripto(1) << endl;
                break;
            }
            case 3:
            {
                auto prueba = make_shared<Curso>("Curso Prueba");

                cout << "Check curso completo:" << endl;
                cout << "* Se crea un curso temporal para probar esto." << endl;
                cout << "* Se checkea el resultado de curso_completo cuando solo tiene un estudiante, lo que devuelve false." << endl;
                cout << "* Luego se añaden 21 estudiantes, lanza un error de curso completo al intentar añadir el estudiante 21." << endl;
                cout << "* Fiinalmente se muestra el resultado de curso_completo que da true" << endl << endl;

                cout << "Curso completo: " << boolalpha << prueba->curso_completo() << endl << endl;
            

                for (int i = 1; i < 22; i++) {
                    cout << "Inscribiendo estudiante nro " << i << endl;

                    try {
                        prueba->inscribir_estudiante(make_shared<Estudiante>("Prueba" + to_string(i), "Prueba" + to_string(i), 70+i), -1);
                    }
                    catch (const std::invalid_argument& e) {
                        cerr << e.what() << endl;
                    } 
                }
                cout << endl;

                prueba->mostrar_estudiantes();

                cout << endl;

                cout << "Curso completo: " << boolalpha << prueba->curso_completo() << endl;
                
                break;
            }
            case 4:
            {
                cout << "Check copiar curso:" << endl;
                

                cout << "Crea una copia del curso 0(Matematica) El nuevo curso va a compartir estudiantes con Matematica,";
                cout << "pero se va a llamar Biologia y sus alumnos van a tener nota -1" << endl << endl;

                shared_ptr<Curso> copia = make_shared<Curso>(*cursos.at(0).get(), "Biologia");
                cursos.push_back(copia);

                cout << "Cursos instanciados y sus estudiantes: " << endl;
                for (auto curso : cursos) {
                    cout << "* ";
                    curso->mostrar_estudiantes();

                    cout << endl;
                }
                cout << endl;
                
                cout << "Eliminando copia..." << endl;
                // En este caso cursos.end() siempre va a ser copia, porque acabo de hacer un push_back
                cursos.erase(cursos.end());

                break;
            }
            default:
                return 0;
        }
        cout << endl;
    } while(accion >= 1 && accion <= 5);
}

u_int getUint() {
    while (true) {
        u_int input {};
        std::cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (std::cin.eof()) {
            exit(0);
        }   

        // Si std::cin no recibe input invalido, std::cin es true.
        bool success { std::cin};

        // Devuelve std::cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();
       
        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            std::cerr << "ERROR: El valor ingresado no es valido, intente de nuevo." << std::endl;
            std::cout << ": ";
        }
    }
}

u_int getUint(u_int range) {
    while (true) {
        u_int input {};
        std::cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (std::cin.eof()) {
            exit(0);
        }   

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que std::cin no haya fallado.
        bool success { std::cin && input < range};

        // Devuelve std::cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();
       
        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            std::cerr << "ERROR: El valor ingresado no es valido, intente de nuevo." << std::endl;
            std::cout << ": ";
        }
    }
}

void mensajeInicial(vector<shared_ptr<Curso>> cursos, vector<shared_ptr<Estudiante>> estudiantes) {
    // Mostrar mensaje de menu
    cout << "Accion: " << endl;
    cout << "1 - Punto i: Inscribir/desinscribir estudiantes." << endl;
    cout << "2 - Punto ii: Verificar estudiante inscripto." << endl;
    cout << "3 - Punto iii: Curso completo." << endl;
    cout << "4 - Punto v: Copiar Curso." << endl;
    cout << "Cualquier otro valor termina el programa." << endl << endl;

    cout << "Cursos instanciados y sus estudiantes: " << endl;
    for (auto curso : cursos) {
        cout << "* ";
        curso->mostrar_estudiantes();

        cout << endl;
    }
    cout << endl;

    cout << "Estudiantes instanciados: " << endl;
    for (auto estudiante : estudiantes) {
        cout << "* " << estudiante.get()->get_nombre_completo();
        cout << " | Legajo: " << estudiante.get()->get_legajo();
        cout << " | Promedio: " << estudiante.get()->get_promedio() << endl;
    }
    cout << endl;
}

void ignoreLine() {
    // numeric_limits<streamsize>::max() es el maximo largo de input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}