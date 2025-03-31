#include <iostream>
#include <string>
#include <limits> // for std::numeric_limits

#include "time.hpp"

using namespace std;

// Da opciones para elegir con que parametros inicializar el momento
Time inputInicializarMomento();
// Toma un puntero a Time, muestra un menu para elegir el valor a cambiar
void inputCambiarMomento(Time* momento);
// Toma un puntero a time, muestra un menu para elegir el formato a mostrar
void inputMostrarMomento(Time* momento);

// Permite tomar por consola el input de usuario, maneja errores de cin, y solo devuelve un u_int, por lo que no permite negativos
u_int getUint();
u_int getUint(u_int tope);

MERIDIEM getMeridiem();

MERIDIEM castMeridiem(u_int meridiem);
void ignoreLine();

int main(){
    u_int accion;
    Time momento{};

    cout << "Bienvenido al ejercicio 1 del Homework 2\n Al momento de inicializar los valores ingresados se redondearan";
    cout << "hacia su unidad superior, por lo que los unicos valores invalidos son negativos o no numericos." << endl; 
    
    do{
        // Mostrar mensaje de menu
        cout << "Accion: " << endl;
        cout << "1 - Inicializar momento" << endl;
        cout << "2 - Cambiar momento" << endl;
        cout << "3 - Mostrar momento" << endl;
        cout << "Cualquier otro valor termina el programa." << endl;

        // Tomar u_int
        cout << "Eleccion: ";
        accion = getUint();

        // Actuar en consecuencia
        switch (accion){
            case 1:
                momento = inputInicializarMomento();
                break;
            case 2:
                inputCambiarMomento(&momento);
                break;
            case 3:
                inputMostrarMomento(&momento);
                break;
            default:
                exit(0);
        }
        cout << endl;
    } while(accion >= 1 && accion <= 3);
}


Time inputInicializarMomento(){
    cout << endl;
    cout << "Ingrese que parametros especificar:" << endl;
    cout << "1: Horas" << endl;
    cout << "2: Horas y Minutos" << endl;
    cout << "3: Horas, Minutos y Segundos" << endl;
    cout << "4: Horas, Minutos, Segundos y Meridiem"<< endl;
    cout << "Cualquier otro numero: Se inicializa todo en 0" << endl;

    cout << "Eleccion: ";


    u_int eleccion = getUint();
    MERIDIEM meridiem;

    string nombres_parametros[] = {"Horas", "Minutos", "Segundos"};
    u_int topes_parametros[] = {12, 60, 60};
    u_int valores_parametros[3];

    if (eleccion >= 1 && eleccion <= 4){
        
        for(u_int i = 0; i < eleccion; i++) {
            if(i != 3) {
                cout << "Ingrese " << nombres_parametros[i] << ": ";
                valores_parametros[i] = getUint();
            }
            else{
                meridiem = getMeridiem();
            }
        }
    }

    switch (eleccion) {
        case 1:
            return Time{valores_parametros[0]};
        case 2:
            return Time{valores_parametros[0], valores_parametros[1]};
        case 3:
            return Time{valores_parametros[0], valores_parametros[1], valores_parametros[2]};
        case 4:
            return Time{valores_parametros[0], valores_parametros[1], valores_parametros[2], meridiem};
        default:
            return Time();
    }   
}

void inputCambiarMomento(Time* momento){
    cout << endl;
    cout << "Ingrese que valor quiere cambiar:" << endl;
    cout << "1: Horas" << endl;
    cout << "2: Minutos" << endl;
    cout << "3: Segundos" << endl;
    cout << "4: Meridiem"<< endl;
    cout << "Con cualquier otro valor vuelve al menu anterior"<< endl;

    cout << "Eleccion: ";

    u_int eleccion = getUint();

    switch (eleccion) {
        case 1:
            cout << "Ingrese Horas: ";
            momento->set_horas(getUint(12));
            break;
        case 2:
            cout << "Ingrese Minutos: ";
            momento->set_minutos(getUint(60));
            break;
        case 3:
            cout << "Ingrese segundos: ";
            momento->set_segundos(getUint(60));
            break;
        case 4:
            momento->set_meridiem(getMeridiem());
            break;
        default: 
            break;
    }
    cout << endl;
}
void inputMostrarMomento(Time* momento){
    cout << endl;
    cout << "Ingrese el formato a mostrar" << endl;
    cout << "1: Formato 12Hs [Hhh Mmm Sss AM/PM]" << endl;
    cout << "2: Formato 24Hs [Hhh Mmm Sss]" << endl;
    cout << "Con cualquier otro valor vuelve al menu anterior"<< endl;

    cout << "Eleccion: ";

    u_int eleccion = getUint();

    switch (eleccion) {
        case 1:
            momento->print_formato12();
            break;
        case 2:
            momento->print_formato24();
            break;
        default: 
            break;
    }
    cout << endl;
}


// Toma un u_int para forzar que sea positivo, no muestra mensaje
u_int getUint() {
    while (true) {
        u_int input {};
        cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (cin.eof()) {
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
            cout << ": ";
        }
    }
}

// Permite tomar un u_int y toma un valor tope(no inclusivo) para valida la entrada.
u_int getUint(u_int tope) {
    while (true) {
        u_int input {};
        cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (cin.eof()) {
            exit(0);
        }   

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que cin no haya fallado.
        bool success { std::cin && input < tope };

        // Devuelve cin a un estado no fail() y limpia el resto del input para evitar errores
        std::cin.clear();
        ignoreLine();
       
        // Si todo salio bien, se devuelve el valor, sino se muestra un error y se pide de nuevo.
        if (success) {
            return input;
        }
        else {
            cerr << "ERROR: El valor ingresado no es valido, intente de nuevo." << endl;
            cout << ": ";
        }
    }
}


MERIDIEM getMeridiem() {
    while (true)
    {   
        // Muestra un mensaje, y toma el input dado
        cout << "Ingrese AM[" << AM << "] o PM[" << PM << "]: ";
        u_int input {};
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

// Cast que solo pasa de un u_int valido, AM o PM, a su equivalente en un enum 
MERIDIEM castMeridiem(u_int meridiem){
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