#include "complejo.hpp"

Complejo::Complejo(float value, float iValue){
    c_intPart = static_cast<int>(value);
    c_realPart = value - c_intPart;
    c_imagPart = iValue;
}

Complejo Complejo::operator+ (const Complejo& rhn) const {
    float rValue1 = this->getIntPart() + this->getRealPart();
    float rValue2 = rhn.getIntPart() + rhn.getRealPart();
    float iValue = this->getImagPart() + rhn.getImagPart(); 

    return Complejo(rValue1 + rValue2, iValue);
}

Complejo Complejo::operator- (const Complejo& rhn) const {
    float rValue1 = this->getIntPart() + this->getRealPart();
    float rValue2 = rhn.getIntPart() + rhn.getRealPart();

    float iValue = this->getImagPart() - rhn.getImagPart(); 

    return Complejo(rValue1 - rValue2, iValue);
}

Complejo Complejo::operator* (const Complejo& rhn) const {
    float rValue1 = this->getIntPart() + this->getRealPart();
    float rValue2 = rhn.getIntPart() + rhn.getRealPart();

    float iValue1 = this->getImagPart();
    float iValue2 = rhn.getImagPart();

    // Se crean 2 numeros complejos que contienen el resultado de la distributiva entre complejos.
    Complejo c1 {rValue1 * rValue2, rValue1 * iValue2};
    // El primer parametro se multiplica por menos 1 porque son dos numeros imaginarios.
    Complejo c2 {(iValue1 * iValue2) * (-1), iValue1 * rValue2};

    return c1 + c2;
}

Complejo Complejo::operator/ (const Complejo& rhn) const {
    Complejo num = *this * Complejo(rhn.getIntPart() + rhn.getRealPart(), -rhn.getImagPart());
    Complejo den = rhn * Complejo(rhn.getIntPart() + rhn.getRealPart(), -rhn.getImagPart());

    if ((den.getIntPart() + den.getRealPart()) == 0){
        throw std::invalid_argument("Division by zero.");
    }
    
    float rValue = (num.getIntPart()+num.getRealPart()) / (den.getIntPart() + den.getRealPart());
    float iValue = num.getImagPart() / (den.getIntPart() + den.getRealPart());

    return Complejo(rValue, iValue);
}

std::ostream& operator<<(std::ostream& os, const Complejo& numero){
    return (os << std::format("{} {} {}i",
           (numero.getIntPart() + numero.getRealPart()), 
           (numero.getImagPart() >= 0) ? '+' : '-',
           numero.getImagPart()));
}

int Complejo::getIntPart() const {
    return c_intPart;
}

float Complejo::getRealPart() const {
    return c_realPart;
}

float Complejo::getImagPart() const {
    return c_imagPart;
}

void Complejo::setIntPart(int value) {
    c_intPart = value;
}

void Complejo::setRealPart(float value) {
    int int_tmp = static_cast<int>(value);
    c_realPart = value - int_tmp;
}

void Complejo::setImagPart(float iValue) {
    c_imagPart = iValue;
}
