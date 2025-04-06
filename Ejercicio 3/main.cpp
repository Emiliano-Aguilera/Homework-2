#include <iostream>

#include "entero.hpp"
#include "real.hpp"
#include "complejo.hpp"

using namespace std;

int main() {
    cout << "Prueba Entero:" << endl;
    
    Numero* e1 = new Entero(9);
    Numero* e2 = new Entero(87);
    Numero* e3 = new Entero(-1);

    cout << "e1: " << e1->toString() << ", e2: " << e2->toString() << ", e3: " << e3->toString() << endl;

    Numero* suma = *e1 + e2;
    Numero* resta = *e2 - e1;
    Numero* producto = *suma * resta; 

    Entero* resultado = dynamic_cast<Entero*>(producto);

    cout << "Resultado de (e1 + e2) * (e2 - e1): " << endl
         << "(" << e1->toString() << " + " << e2->toString() << ") * (" 
         << e2->toString() << " - " << e1->toString() << ") = " 
         << resultado->toString() << endl;

    delete suma;
    delete resta;
    delete producto;
    
    delete e1;
    delete e2;
    delete e3;
    
    cout << "Prueba Real:" << endl;
    Numero* r1 = new Real(9.8);
    Numero* r2 = new Real(87.1);
    Numero* r3 = new Real(-1.5);

    cout << "r1: " << r1->toString() << ", r2: " << r2->toString() << ", r3: " << r3->toString() << endl;

    Numero* sumaReal = *r1 + r2;
    Numero* restaReal = *r2 - r1;
    Numero* productoReal = *sumaReal * restaReal;
    
    Real* resultadoReal = dynamic_cast<Real*>(productoReal);
    
    cout << "Resultado de (r1 + r2) * (r2 - r1): " << endl 
         << "(" << r1->toString() << " + " << r2->toString() << ") * (" 
         << r2->toString() << " - " << r1->toString() << ") = " 
         << resultadoReal->toString() << endl;
    
    delete sumaReal;
    delete restaReal;
    delete productoReal;
    
    delete r1;
    delete r2;
    delete r3;
    
    cout << "Prueba Complejo:" << endl;

    Numero* c1 = new Complejo(9.8, -500.8);
    Numero* c2 = new Complejo(87.1, 7.4);
    Numero* c3 = new Complejo(-1.5, 0);

    cout << "c1: " << c1->toString() << ", c2: " << c2->toString() << ", c3: " << c3->toString() << endl;

    Numero* sumaComplejo = *c1 + c2;
    Numero* restaComplejo = *c2 - c1;
    Numero* productoComplejo = *sumaComplejo * restaComplejo;
    
    Complejo* resultadoComplejo = dynamic_cast<Complejo*>(productoComplejo);
    
    cout << "Resultado de (c1 + c2) * (c2 - c1): " << endl
         << "(" << c1->toString() << " + " << c2->toString() << ") * (" 
         << c2->toString() << " - " << c1->toString() << ") = " 
         << resultadoComplejo->toString() << endl;

    delete sumaComplejo;
    delete restaComplejo;
    delete productoComplejo;
    
    delete c1;
    delete c2;
    delete c3;
    
    cout << endl << "Fin pruebas." << endl;
    return 0;
}