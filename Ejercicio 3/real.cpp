#include "real.hpp"

Real::Real(float value){
    r_intPart = static_cast<int>(value);
    r_realPart = value - r_intPart;
}

Real Real::operator+ (const Real& rhn) const {
    float value1 = this->getIntPart() + this->getRealPart();
    float value2 = rhn.getIntPart() + rhn.getRealPart();
    
    return Real(value1 + value2);
}

Real Real::operator- (const Real& rhn) const {
    float value1 = this->getIntPart() + this->getRealPart();
    float value2 = rhn.getIntPart() + rhn.getRealPart();
    
    return Real(value1 - value2);
}

Real Real::operator* (const Real& rhn) const {
    float value1 = this->getIntPart() + this->getRealPart();
    float value2 = rhn.getIntPart() + rhn.getRealPart();

    return Real(value1 * value2);
}

Real Real::operator/ (const Real& rhn) const {
    float value1 = this->getIntPart() + this->getRealPart();
    float value2 = rhn.getIntPart() + rhn.getRealPart();

    if (value2 == 0.0){
        throw std::invalid_argument("Division by zero.");
    }
    
    return Real(value1 / value2);
}

std::ostream& operator<<(std::ostream& os, const Real& numero){
    return (os << std::format("{}", (numero.getIntPart() + numero.getRealPart())));
}

int Real::getIntPart() const {
    return r_intPart;
}

float Real::getRealPart() const {
    return r_realPart;
}

void Real::setIntPart(int value) {
    r_intPart = value;
}

void Real::setRealPart(float value) {
    int int_tmp = static_cast<int>(value);
    r_realPart = value - int_tmp;
}
