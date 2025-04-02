#include "complejo.hpp"

Complejo::Complejo(float value, float iValue){
    intPart = static_cast<int>(value);
    realPart = value - intPart;
    imagPart = iValue;
}

Complejo Complejo::operator+ (const Complejo& rhn) const {
    float Value1 = intPart + realPart;
    float Value2 = rhn.getIntPart() + rhn.getRealPart();
    float iValue = imagPart + rhn.getImagPart(); 

    return Complejo(Value1 + Value2, iValue);
}

Complejo Complejo::operator- (const Complejo& rhn) const {
    float Value1 = intPart + realPart;
    float Value2 = rhn.getIntPart() + rhn.getRealPart();

    float iValue = imagPart - rhn.getImagPart(); 

    return Complejo(Value1 - Value2, iValue);
}

Complejo Complejo::operator* (const Complejo& rhn) const {
    float Value1 = intPart + realPart;
    float Value2 = rhn.getIntPart() + rhn.getRealPart();

    float iValue1 = imagPart;
    float iValue2 = rhn.getImagPart();

    // Se crean 2 numeros complejos que contienen el resultado de la distributiva entre complejos.
    Complejo c1 {Value1 * Value2, Value1 * iValue2};
    // El primer parametro se multiplica por menos 1 porque son dos numeros imaginarios.
    Complejo c2 {(iValue1 * iValue2) * (-1), iValue1 * Value2};

    return c1 + c2;
}

Complejo Complejo::operator/ (const Complejo& rhn) const {
    Complejo conjRhn(rhn.getIntPart() + rhn.getRealPart(), -(rhn.getImagPart()));

    Complejo num = *this * conjRhn;
    Complejo den = rhn * conjRhn;

    if ((den.getIntPart() + den.getRealPart()) == 0){
        throw std::invalid_argument("Division by zero.");
    }
    
    float rValue = (num.getIntPart()+num.getRealPart()) / (den.getIntPart() + den.getRealPart());
    float iValue = num.getImagPart() / (den.getIntPart() + den.getRealPart());

    return Complejo(rValue, iValue);
}

std::string Complejo::toString() const {
    return std::format("{} {} {}i", (intPart + realPart), (imagPart >= 0) ? '+' : '-', imagPart);
}
