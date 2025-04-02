#include "entero.hpp"

Entero::Entero(int value){
    intPart = value;
}

Entero Entero::operator+ (const Entero& rhn) const {
    return Entero(this->intPart + rhn.intPart);
}
Entero Entero::operator- (const Entero& rhn) const {
    return Entero(this->intPart - rhn.intPart);
}
Entero Entero::operator* (const Entero& rhn) const {
    return Entero(this->intPart * rhn.intPart);
}
Entero Entero::operator/ (const Entero& rhn) const {
    if (rhn.intPart == 0) {
        throw std::invalid_argument("Division by zero.");
    }

    return Entero(this->intPart / rhn.intPart);
}

std::string Entero::toString() const {
    return std::format("{}", intPart);
}