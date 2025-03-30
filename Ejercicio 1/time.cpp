#include "time.hpp"
#include <iostream>

std::string meridiem_strings[2] = {"a.m.", "p.m."};

// Permite inicializar con valores mayores a 12, 60, 60, respectivamente. 
// Cuando los valores se pasan, estos suman su equivalente a la unidad que le sigue:
// segundos = 123 suma 2 minutos y deja segundos en 3, lo mismo con minutos.
// En el caso de Horas, depende del meridiem, si meridiem = AM y horas = 13,
// entonces meridiem pasa a PM y horas a 1. Lo mismo si fuese PM, pasaria a AM.
Time::Time(int horas, int minutos, int segundos, MERIDIEM meridiem) {
    set_segundos(segundos);
    set_minutos(minutos);
    set_meridiem(meridiem);
    set_horas(horas);
    
}

// Toma una cantidad de horas, si es mayor a 12 cambia el meridiem, ya sea de AM a PM o viceversa
// y horas toma el valor restante a 12. horas = 14 meridiem = PM -> horas = 2 meridiem = AM.
void Time::set_horas(int horas){
    if ((horas + t_horas) <= 12) {
        t_horas = horas;
    }
    else {
        if (t_meridiem == AM) {
            set_meridiem(PM);   
            t_horas = (t_horas + horas) % 12;
        } else {
            set_meridiem(AM);   
            t_horas = (t_horas + horas) % 12;
        }
    }
}

// Si la cantidad de minutos es mayor a 60, se añaden a horas y minutos obtiene el resto.
void Time::set_minutos(int minutos){
    
    if ((minutos + t_minutos) <= 60){
        t_minutos = minutos;
    }
    else {
        t_horas += (minutos + t_minutos) / 60;
        t_minutos = (minutos + t_minutos) % 60;
    }
}

// Si la cantidad de segundos es mayor a 60, se suma a minutos y segundos obtiene el resto.
void Time::set_segundos(int segundos){
    if (segundos <= 60) {
        t_segundos = segundos;
    }
    else{
        t_minutos += segundos / 60;
        t_segundos = segundos % 60;
    }
}

// Si el meridiem dado no es AM ni PM lanza error.
void Time::set_meridiem(MERIDIEM meridiem) {
    if (meridiem == AM || meridiem == PM){
        t_meridiem = meridiem;
    }
    else{
        throw std::invalid_argument("El meridiem debe ser AM o PM.");
    }
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


void Time::print_formato12(){
    std::cout << t_horas << "h, " << t_minutos << "m, " << t_segundos << "s " << meridiem_strings[t_meridiem] << std::endl;
};

void Time::print_formato24(){
    if(t_meridiem == AM){
        std::cout << t_horas << "h, " << t_minutos << "m, " << t_segundos << "s "<< std::endl;
    }
    else {
        int m_hours24 = (t_horas + 12) % 24;

        std::cout << m_hours24 << "h, " << t_minutos << "m, " << t_segundos << "s "<< std::endl;
    }
}