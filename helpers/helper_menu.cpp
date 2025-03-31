#include "helper_menu.hpp"

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

u_int getUint(u_int tope) {
    while (true) {
        u_int input {};
        std::cin >> input;

        // Check si el usuario ingresa EOF, el programa deberia cerrarse
        if (std::cin.eof()) {
            exit(0);
        }   

        // success determina si se devuelve o no el input, lo determina que este dentro del rango y que std::cin no haya fallado.
        bool success { std::cin && input < tope };

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

void ignoreLine() {
    // numeric_limits<streamsize>::max() es el maximo largo de input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}