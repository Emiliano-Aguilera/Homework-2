#include <iostream>

#include "entero.hpp"
#include "real.hpp"
#include "complejo.hpp"

using namespace std;

int main() {
    cout << "Prueba Entero:" << endl;
    Entero e1(9);
    Entero e2(87);
    Entero e3(-1);

    cout << "Resultado de (e1 + e2) * (e2 - e1)" << endl;
    cout << "(" << e1 << " + " << e2 << ")" << " * " << "(" << e2 << " - " << e1 << ") = ";
    cout << (e1 + e2) * (e2 - e1) << endl << endl;

    cout << "Resultado de (e1 + e2) / (e1 * e3)" << endl;
    cout << "(" << e1 << " + " << e2 << ")" << " / " << "(" << e1 << " * " << e3 << ") = ";
    cout << (e1 + e2) / (e1 * e3) << endl << endl;

    try {
        cout << "Ejemplo division por cero: ";
        Entero e4(0);
        cout << "Resultado de e2 / e4" << endl;
        cout << e2 << "/" << e4 << " = ";

        cout << (e2 / e4) << endl;
    } catch (std::invalid_argument const& error) {
        cerr << "ERROR: " << error.what() << endl;
        //return 1; 
    }


    cout << "=========================" << endl;
    cout << "=========================" << endl;
    
    cout << "Prueba Real:" << endl;
    Real r1(9.8);
    Real r2(87.1);
    Real r3(-1.5);

    cout << "Resultado de (r1 + r2) * (r2 - r1)" << endl;
    cout << "(" << r1 << " + " << r2 << ")" << " * " << "(" << r2 << " - " << r1 << ") = ";
    cout << (r1 + r2) * (r2 - r1) << endl << endl;

    cout << "Resultado de (r1 + r2) / (r1 * r3)" << endl;
    cout << "(" << r1 << " + " << r2 << ")" << " / " << "(" << r1 << " * " << r3 << ") = ";
    cout << (r1 + r2) / (r1 * r3) << endl << endl;

    try {
        cout << "Ejemplo division por cero: r4 = ";
        Real r4(0.0);

        cout << "Resultado de r2 / r4" << endl;
        cout << r2 << " / " << r4 << " = ";
        cout << (r2 / r4) << endl;
    } catch (std::invalid_argument const& error) {
        cerr << "ERROR: " << error.what() << endl;
        //return 1;
    }

    cout << "=========================" << endl;
    cout << "=========================" << endl;
    
    cout << "Prueba Complejo:" << endl;
    Complejo c1(9.8, -500.8);
    Complejo c2(87.1, 7.4);
    Complejo c3(-1.5, 0);

    cout << "Resultado de (c1 + c2) * (c2 - c1)" << endl;
    cout << "(" << c1 << " + " << c2 << ")" << " * " << "(" << c2 << " - " << c1 << ") = ";
    cout << (c1 + c2) * (c2 - c1) << endl << endl;

    cout << "Resultado de (c1 + c2) / (c1 * c3)" << endl;
    cout << "(" << c1 << " + " << c2 << ")" << " / " << "(" << c1 << " * " << c3 << ") = ";
    cout << (c1 + c2) / (c1 * c3) << endl << endl;

    try {
        cout << "Ejemplo division por cero: r4 = ";
        Complejo r4(0.0, 0.0);

        cout << "Resultado de c2 / r4" << endl;
        cout << c2 << " / " << r4 << " = ";
        cout << (c2 / r4) << endl;
    } catch (std::invalid_argument const& error) {
        cerr << "ERROR: " << error.what() << endl;
        //return 1; deshabilitado, pero seria el comportamiento correcto.
    }

    cout << endl << "Fin pruebas." << endl;

    return 0;
}