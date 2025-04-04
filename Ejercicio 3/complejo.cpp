#include "complejo.hpp"

Complejo::Complejo(float value, float iValue){
    realPart = value;
    imagPart = iValue;
}

std::shared_ptr<Numero> Complejo::operator+ (const Complejo& rhn) const {
    float value = realPart + rhn.getRealPart();
    float iValue = imagPart + rhn.getImagPart(); 

    return std::make_shared<Complejo>(value, iValue);
}

std::shared_ptr<Numero> Complejo::operator- (const Complejo& rhn) const {
    float value = realPart - rhn.getRealPart();
    float iValue = imagPart - rhn.getImagPart();

    return std::make_shared<Complejo>(value, iValue);
}

std::shared_ptr<Numero> Complejo::operator* (const Complejo& rhn) const {
    // Se crean 2 numeros complejos que contienen el resultado de la distributiva entre complejos.
    Complejo c1 {realPart * rhn.getRealPart(), realPart * rhn.getImagPart()};
    // El primer parametro se multiplica por menos 1 porque son dos numeros imaginarios.
    Complejo c2 {(imagPart* rhn.getImagPart()) * (-1), imagPart * rhn.getRealPart()};

    return make_shared<Complejo>(c1 + c2);
}

float Complejo::getRealPart() const {
    return realPart;
}
void Complejo::setRealPart(float value){
    realPart = value;
}

float Complejo::getImagPart() const {
    return imagPart;
}
void Complejo::setImagPart(float iValue){
    imagPart = iValue;
}

std::string Complejo::toString() const {
    return std::format("{} {} {}i", realPart, (imagPart >= 0) ? '+' : '-', imagPart);
}
