#include "entero.hpp"

Entero::Entero(int value){
    valor = value;
}

Numero* Entero::operator+ (const Numero* rhn) const {
    const Entero* int_rhn = dynamic_cast<const Entero*>(rhn);
    return new Entero(valor + int_rhn->getValor());
}

Numero* Entero::operator- (const Numero* rhn) const {
    const Entero* int_rhn = dynamic_cast<const Entero*>(rhn);
    return new Entero(valor - int_rhn->getValor());
}

Numero* Entero::operator* (const Numero* rhn) const {
    const Entero* int_rhn = dynamic_cast<const Entero*>(rhn);
    return new Entero(valor * int_rhn->getValor());
}

std::string Entero::toString() const {
    return std::format("{}", valor);
}

int Entero::getValor() const {
    return valor;
}

