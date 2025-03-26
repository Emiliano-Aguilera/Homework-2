#include <iostream>
#include <string>

#include "time.hpp"

using namespace std;

void printOptions();
int getInput();
void getInputTime(Time moment);

int main(){
    int option;
    Time moment;
    do{
        printOptions();
        try {
            cout << "Opcion: ";
            option = getInput();
            switch (option) {
                case 0:
                    
            }
        }
        catch (...) {
            cout << "Valor invalido." << endl;
        }
    } while (option > 0 && option < 9);

}

void printOptions(){
    cout << "Seleccione una accion:" << endl;
    cout << "0  - Inicializar sin parametros.\n"
         << "1  - Inicializar con Horas.\n"
         << "2  - Inicializar con Horas y Minutos.\n"
         << "3  - Inicializar con Horas, Minutos y Segundos.\n"
         << "4  - Inicializar con Horas, Minutos, Segundos y Meridiem\n"
         << "5  - Cambiar Horas\n"
         << "6  - Cambiar Minutos\n"
         << "7  - Cambiar Segundos\n"
         << "8  - Cambiar Meridiem\n"
         << "9  - Ver Horas\n"
         << "10 - Ver Minutos\n"
         << "11 - Ver Segundos\n"
         << "12 - Ver Meridiem\n"
         << "Cualquier otro numero para salir.\n";    
}

int getInput(){
    string input;
    std::getline(cin, input);
    int intInput;
    
    try{
        intInput = stoi(input);
    }
    catch (invalid_argument const& ex){
        throw ex;
    }
    catch(out_of_range const& ey){
        throw ey;
    }
    
    return intInput;
}

void getInputTime(Time moment) {
    cout << "Horas: ";
    int horas = getInput();

    cout << "Minutos: ";
    int minutos = getInput();

    cout << "Segundos: ";
    int segundos = getInput();

    cout << "a.m.(0) p.m.(1): ";
    int am = getInput();
}


