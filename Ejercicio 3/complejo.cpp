#include "complejo.hpp"

Complejo::Complejo(double rValue, double iValue){
    valorReal = rValue;
    valorImag = iValue;
}

Numero* Complejo::operator+ (const Numero* rhn) const {
    const Complejo* cast_rhn = dynamic_cast<const Complejo*>(rhn);
    return new Complejo(valorReal + cast_rhn->getValorReal(), valorImag + cast_rhn->getValorImag());
}

Numero* Complejo::operator- (const Numero* rhn) const {
    const Complejo* cast_rhn = dynamic_cast<const Complejo*>(rhn);
    return new Complejo(valorReal - cast_rhn->getValorReal(), valorImag - cast_rhn->getValorImag());
}

Numero* Complejo::operator* (const Numero* rhn) const {
    const Complejo* cast_rhn = dynamic_cast<const Complejo*>(rhn);
    
    double realA = valorReal;
    double imagA = valorImag;
    double realB = cast_rhn->valorReal;
    double imagB = cast_rhn->valorImag;

    double resultadoReal = realA * realB - imagA * imagB;
    double resultadoImag = realA * imagB + imagA * realB;

    return new Complejo(resultadoReal, resultadoImag);
}

std::string Complejo::toString() const {
    return std::format("{} + {}i", valorReal, valorImag);
}

double Complejo::getValorReal() const {
    return valorReal;
}

double Complejo::getValorImag() const {
    return valorImag;
}
