#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Real : public Numero {
    public:
        Real(float value);

        // Devuelve un Real cuyo valor es la suma de los operandos
        Real operator+ (const Real& rhn) const;
        // Devuelve un Real cuyo valor es la resta de los operandos
        Real operator- (const Real& rhn) const;
        // Devuelve un Real cuyo valor es el producto entre los operandos
        Real operator* (const Real& rhn) const;
        // Devuelve un Real cuyo valor es la division de los operandos
        Real operator/ (const Real& rhn) const;

        // Como Real no tiene parte imaginaria, sus metodos correspondientes se inhabilitan.

        float getImagPart() const = delete;
        void setImagPart(float iValue) = delete;

        std::string toString() const override;
};
