#include "entero.hpp"

Entero::Entero(int value){
    e_value = value;
}

Entero Entero::operator+ (const Entero& rhn) const {
    return Entero(this->e_value + rhn.e_value);
}
Entero Entero::operator- (const Entero& rhn) const {
    return Entero(this->e_value - rhn.e_value);
}
Entero Entero::operator* (const Entero& rhn) const {
    return Entero(this->e_value * rhn.e_value);
}
Entero Entero::operator/ (const Entero& rhn) const {
    if (rhn.e_value == 0) {
        throw std::invalid_argument("Division by zero.");
    }

    return Entero(this->e_value / rhn.e_value);
}

std::ostream& operator<<(std::ostream& os, const Entero& numero){
    return (os << std::to_string(numero.getIntPart()));
}

int Entero::getIntPart() const {
    return e_value;
}

void Entero::setIntPart(int value) {
    e_value = value;
}