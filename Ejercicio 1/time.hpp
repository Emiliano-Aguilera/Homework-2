#pragma once

#include <string>
#include <iostream>

enum MERIDIEM {AM, PM};

class Time{
    public:
        int t_horas{};
        int t_minutos{};
        int t_segundos{};
        MERIDIEM t_meridiem{AM};
    public:
        Time(int hours = 0, int minutes = 0, int seconds = 0, MERIDIEM am = AM);
        
        // Setters
        void set_horas(int);
        void set_minutos(int);
        void set_segundos(int);
        void set_meridiem(MERIDIEM);

        // Getters
        int get_horas();
        int get_minutos();
        int get_segundos();
        MERIDIEM get_meridiem();

        // Metodos que imprimen en formato 12 y 24 horas
        // Imprime el momento en formato H M S am/pm
        void print_formato12();
        // Imprime el momento en formato H M S
        void print_formato24();
};