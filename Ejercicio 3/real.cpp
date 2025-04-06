#include "real.hpp"

Real::Real(double value){
    valor = value;
}

Numero* Real::operator+ (const Numero* rhn) const {
    const Real* int_rhn = dynamic_cast<const Real*>(rhn);
    return new Real(valor + int_rhn->getValor());
}

Numero* Real::operator- (const Numero* rhn) const {
    const Real* int_rhn = dynamic_cast<const Real*>(rhn);
    return new Real(valor - int_rhn->getValor());
}

Numero* Real::operator* (const Numero* rhn) const {
    const Real* int_rhn = dynamic_cast<const Real*>(rhn);
    return new Real(valor * int_rhn->getValor());
}

std::string Real::toString() const {
    return std::format("{}", valor);
}

double Real::getValor() const {
    return valor;
}

