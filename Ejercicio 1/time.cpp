#include "time.hpp"
#include <iostream>

std::string meridiemStrings[2] = {"a.m.", "p.m."};

Time::Time(int hours, int minutes, int seconds, Meridiem am)
{
    if (hours <= 12) {
        m_hours = {hours};
    }
    else {
        m_hours = hours % 12;
    }
    if (minutes <= 60){
        m_minutes = {minutes};
    }
    else {
        m_minutes = minutes % 60;
    }
    if (seconds <= 60) {
        m_seconds = {seconds};
    }
    else{
        m_seconds = seconds % 60;
    }
    m_meridiem = {am};
}

void Time::printTime12(){
    std::cout << m_hours << "h, " << m_minutes << "m, " << m_seconds << "s " << meridiemStrings[m_meridiem] << std::endl;
};

void Time::printTime24(){
    if(m_meridiem == AM){
        std::cout << m_hours << "h, " << m_minutes << "m, " << m_seconds << "s "<< std::endl;
    }
    else {
        int m_hours24 = (m_hours + 12) % 24;

        std::cout << m_hours24 << "h, " << m_minutes << "m, " << m_seconds << "s "<< std::endl;
    }
}

// Setters
void Time::setHours(int hours){
    if (hours < 12) {
        m_hours = {hours};
    }
    else {
        m_hours = hours % 12;
    }
}

void Time::setMinutes(int minutes){
    if (minutes < 60) {
        m_minutes = {minutes};
    }
    else {
        m_minutes = minutes % 60;
    }
}

void Time::setSeconds(int seconds){
    if (seconds < 60) {
        m_seconds = {seconds};
    }
    else {
        m_seconds = seconds % 60;
    }
}

void Time::setMeridiem(Meridiem am) {
    m_meridiem = am;
}

// Sobrecarga de setters, las que no toman parametros se encargan del input.
void Time::setHours(){

}

void Time::setMinutes(){

}

void Time::setSeconds(){

}

void Time::setMeridiem() {

}


// Getters
int Time::getHours() {
    return m_hours;
}

int Time::getMinutes(){
    return m_minutes;
}

int Time::getSeconds(){
    return m_seconds;
}

Meridiem Time::getMeridiem(){
    return m_meridiem;
}