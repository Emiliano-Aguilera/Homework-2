#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Complejo : public Numero {
    public:
        Complejo(float value, float iValue);

        // Devuelve un Complejo cuyo valor es la suma de los operandos
        Complejo operator+ (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es la resta de los operandos
        Complejo operator- (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es el producto entre los operandos
        Complejo operator* (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es la division de los operandos
        Complejo operator/ (const Complejo& rhn) const;

        std::string toString() const override;
};
