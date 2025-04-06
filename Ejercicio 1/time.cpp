#include "time.hpp"
#include <iomanip> // Include iomanip for formatting

const std::string meridiem_strings[2] = {"a.m.", "p.m."};

// Permite inicializar con valores mayores a 12, 60, 60, respectivamente. 
// Cuando los valores se pasan del maximo, estos suman su equivalente a la unidad que le sigue, por ejemplo:
// segundos = 123 suma 2 minutos y deja segundos en 3, lo mismo con minutos.
// En el caso de Horas, depende del meridiem, si meridiem = AM y horas = 13,
// entonces meridiem pasa a PM y horas a 1. Lo mismo si fuese PM, pasaria a AM.
Time::Time(int horas, int minutos, int segundos, MERIDIEM meridiem) {
    set_segundos(segundos % 60);
    set_minutos((minutos + segundos / 60) % 60);
    int total_horas = horas + (minutos + segundos / 60) / 60;

    if (total_horas > 12) {
        int meridiem_flips = (total_horas - 1) / 12;
        set_horas(total_horas % 12 == 0 ? 12 : total_horas % 12);
        set_meridiem((meridiem_flips % 2 == 0) ? meridiem : (meridiem == AM ? PM : AM));
    } else {
        set_horas(total_horas == 0 ? 12 : total_horas);
        set_meridiem(meridiem);
    }
}

// Si la cantidad de horas es mayor a 12 o menor a 1, lanza error.
void Time::set_horas(int horas) {
    if (horas < 1 || horas > 12) {
        throw std::invalid_argument("Las horas deben estar entre 1 y 12.");
    }
    t_horas = horas;
}

// Si la cantidad de minutos es mayor a 60 o menor a 0, lanza error.
void Time::set_minutos(int minutos) {
    if (minutos < 0 || minutos >= 60) {
        throw std::invalid_argument("Los minutos deben estar entre 0 y 59.");
    }
    t_minutos = minutos;
}

// Si la cantidad de segundos es mayor a 60 o menor a 0, lanza error.
void Time::set_segundos(int segundos) {
    if (segundos < 0 || segundos >= 60) {
        throw std::invalid_argument("Los segundos deben estar entre 0 y 59.");
    }
    t_segundos = segundos;
}

// Si el meridiem dado no es AM ni PM, lanza error.
void Time::set_meridiem(MERIDIEM meridiem) {
    if (meridiem != AM && meridiem != PM) {
        throw std::invalid_argument("El meridiem debe ser AM o PM.");
    }
    t_meridiem = meridiem;
}


int Time::get_horas() {
    return t_horas;
}

int Time::get_minutos(){
    return t_minutos;
}

int Time::get_segundos(){
    return t_segundos;
}

MERIDIEM Time::get_meridiem(){
    return t_meridiem;
}

// Imprime en formato 12 horas, con formato consistente.
void Time::print_formato12() {
    int horas12 = (t_horas == 0) ? 12 : t_horas; // Adjust 0 to 12 for 12-hour format
    std::cout << "Momento: " 
              << std::setw(2) << std::setfill('0') << horas12 << "h, "
              << std::setw(2) << std::setfill('0') << t_minutos << "m, "
              << std::setw(2) << std::setfill('0') << t_segundos << "s "
              << meridiem_strings[t_meridiem] << std::endl;
}

// Imprime en formato 24 horas, con formato consistente.
void Time::print_formato24() {
    int horas24 = (t_horas == 12 && t_meridiem == AM) ? 0 : (t_horas + (t_meridiem == PM ? 12 : 0));
    std::cout << "Momento: " 
              << std::setw(2) << std::setfill('0') << horas24 << "h, "
              << std::setw(2) << std::setfill('0') << t_minutos << "m, "
              << std::setw(2) << std::setfill('0') << t_segundos << "s "
              << std::endl;
}