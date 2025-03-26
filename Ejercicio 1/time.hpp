#pragma once
#include <string>

enum Meridiem {AM, PM};

class Time{
    public:
        int m_hours{};
        int m_minutes{};
        int m_seconds{};
        Meridiem m_meridiem{};
    public:
        Time(int hours = 0, int minutes = 0, int seconds = 0, Meridiem am = AM);
        void printTime12();
        void printTime24();

        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);
        void setMeridiem(Meridiem);

        void setHours();
        void setMinutes();
        void setSeconds();
        void setMeridiem();

        int getHours();
        int getMinutes();
        int getSeconds();
        Meridiem getMeridiem();
};