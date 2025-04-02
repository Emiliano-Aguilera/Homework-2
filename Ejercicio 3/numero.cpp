#include "numero.hpp"

// Sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Numero& numero) {
    return os << numero.toString();
}

// Setters
void Numero::setIntPart(int value) {
    intPart = value;
}

void Numero::setRealPart(float value) {
    int int_tmp = static_cast<int>(value);
    realPart = value - int_tmp;
}

void Numero::setImagPart(float iValue) {
    imagPart = iValue;
}

// Getters
int Numero::getIntPart() const {
    return intPart;
}

float Numero::getRealPart() const {
    return realPart;
}

float Numero::getImagPart() const {
    return imagPart;
}