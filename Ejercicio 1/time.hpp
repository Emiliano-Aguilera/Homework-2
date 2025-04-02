#pragma once

#include <string>
#include <iostream>

enum MERIDIEM {AM, PM};

class Time{
    public:
        u_int t_horas{};
        u_int t_minutos{};
        u_int t_segundos{};
        MERIDIEM t_meridiem{AM};
    public:
        Time(u_int hours = 0, u_int minutes = 0, u_int seconds = 0, MERIDIEM am = AM);
        
        // Setters
        void set_horas(u_int);
        void set_minutos(u_int);
        void set_segundos(u_int);
        void set_meridiem(MERIDIEM);

        // Getters
        u_int get_horas();
        u_int get_minutos();
        u_int get_segundos();
        MERIDIEM get_meridiem();

        // Metodos que imprimen en formato 12 y 24 horas
        // Imprime el momento en formato H M S am/pm
        void print_formato12();
        // Imprime el momento en formato H M S
        void print_formato24();
};