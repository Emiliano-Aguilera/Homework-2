#include <iostream>
#include <string>
#include <limits> // for std::numeric_limits

#include "time.hpp"

using namespace std;

int getInt(string tipo);
MERIDIEM getMeridiem();

MERIDIEM castMeridiem(int meridiem);
void ignoreLine();

int main(){
    Time momento = Time(getInt("horas"), getInt("minutos"), getInt("segundos"), getMeridiem()); 
    momento.print_formato12();
}



// Toma un tipo de entrada, valida que el input este dentro del rango del tipo y maneja errores de cin.
int getInt(string tipo) {
    while (true)
    {   
        // Muestra un mensaje, y toma el input dado
        cout << "Ingrese cantidad de " << tipo << ": ";
        int input {};
        cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (cin.eof())
        {
            exit(0);
        }   

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que cin no haya fallado.
        bool success { std::cin};

        // Devuelve cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();
       
        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            cerr << "ERROR: El valor ingresado no es valido, intente de nuevo." << endl;
        }
    }
}


MERIDIEM getMeridiem() {
    while (true)
    {   
        // Muestra un mensaje, y toma el input dado
        cout << "Ingrese AM[" << AM << "] o PM[" << PM << "]: ";
        int input {};
        cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (cin.eof())
        {
            exit(0);
        }

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que cin no haya fallado.
        bool success { std::cin && (input == AM || input == PM)};

        // Devuelve cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();

        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return castMeridiem(input);
        }
        else {
            cerr << "ERROR: El valor ingresado no es valido, intente de nuevo." << endl;
        }
    }
}

// Cast que solo pasa de un int valido, AM o PM, a su equivalente en un enum 
MERIDIEM castMeridiem(int meridiem){
    switch (meridiem) {
        case AM:
            return AM;
        case PM:
            return PM;
        default:
            return AM;
    }
}

// Ignora todos los caracteres posibles, o hasta un \n. Sirve para evitar errores en los que el usuario 
    // ingresa una secuencia de entrada valida en el primer input, lo que rompe el flujo del programa
void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}