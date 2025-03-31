#include "time.hpp"
#include <iostream>

std::string meridiem_strings[2] = {"a.m.", "p.m."};

// Permite inicializar con valores mayores a 12, 60, 60, respectivamente. 
// Cuando los valores se pasan del maximo, estos suman su equivalente a la unidad que le sigue, por ejemplo:
// segundos = 123 suma 2 minutos y deja segundos en 3, lo mismo con minutos.
// En el caso de Horas, depende del meridiem, si meridiem = AM y horas = 13,
// entonces meridiem pasa a PM y horas a 1. Lo mismo si fuese PM, pasaria a AM.
Time::Time(u_int horas, u_int minutos, u_int segundos, MERIDIEM meridiem) {
    // Si hay menos de 60 segundos, se setean, sino se asignan los minutos correspondientes a t_minutos y el resto a segundos.
    if (segundos < 60) {
        t_segundos = segundos;
    }
    else{
        t_minutos += segundos / 60;
        t_segundos = segundos % 60;
    }

    // Si la cantidad redondeada por segundos y los minutos dados, son mayores a 60, se suman las horas correspondientes y el resto va a minutos.
    if ((minutos + t_minutos) < 60){
        t_minutos += minutos;
    }
    else {
        t_horas += (minutos + t_minutos) / 60;
        t_minutos = (minutos + t_minutos) % 60;
    }

    // Si la cantidad de horas redondeada por minutos sumada a las horas dadas, es mayor a 12, se cambia el meridiem y se acota horas a 0-12.
    if ((horas + t_horas) <= 12) {
        t_horas += horas;
    }
    else {
        // Dependiendo de la cantidad de horas el meridiem cambia o no, segun si se pasa menos o mas de un dia.
        if ((((horas + t_horas) / 12) % 2) == 1){
            if (t_meridiem == AM){
                set_meridiem(PM);   
                t_horas = (t_horas + horas) % 12;
            }
            else{
                set_meridiem(AM);
                t_horas = (t_horas + horas) % 12;
            }
        }
        else {
            t_horas = (t_horas + horas) % 12;
        }
    }

    if (meridiem == AM || meridiem == PM){
        t_meridiem = meridiem;
    }
    else{
        throw std::invalid_argument("El meridiem debe ser AM o PM.");
    }
}

// Toma una cantidad de horas, si es mayor a 12 lo acota a 12 usando modulo
void Time::set_horas(u_int horas){
    t_horas = horas;
}

// Si la cantidad de minutos es mayor a 60, acota la cantidad a 60
void Time::set_minutos(u_int minutos){
    t_minutos = minutos;
}

// Si la cantidad de segundos es mayor a 60 acota la cantidad a 60
void Time::set_segundos(u_int segundos){
    t_segundos = segundos;
}

// Si el meridiem dado no es AM ni PM lanza error.
void Time::set_meridiem(MERIDIEM meridiem) {
    t_meridiem = meridiem;
}


u_int Time::get_horas() {
    return t_horas;
}

u_int Time::get_minutos(){
    return t_minutos;
}

u_int Time::get_segundos(){
    return t_segundos;
}

MERIDIEM Time::get_meridiem(){
    return t_meridiem;
}

// Imprime en formato 12 horas, no tiene logica.
void Time::print_formato12(){
    std::cout << "Momento: " << t_horas << "h, " << t_minutos << "m, " << t_segundos << "s " << meridiem_strings[t_meridiem] << std::endl;
};

// Cuando meridiem es AM, el printeo no implica ningun calculo, cuando es PM se le suma 12 a las horas
void Time::print_formato24(){
    if(t_meridiem == AM){
        std::cout << "Momento: " << t_horas << "h, " << t_minutos << "m, " << t_segundos << "s "<< std::endl;
    }
    else {
        u_int m_hours24 = t_horas + 12; // No se acota, ya que t_horas nunca va a ser mayor a 12.

        std::cout << "Momento: " << m_hours24 << "h, " << t_minutos << "m, " << t_segundos << "s "<< std::endl;
    }
}