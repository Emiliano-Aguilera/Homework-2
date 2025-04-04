#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>
#include <memory>

class Complejo : public Numero {
    private:
        float realPart;
        float imagPart;
    public:
        Complejo(float value, float iValue);

        // Devuelve un Complejo cuyo valor es la suma de los operandos
        std::shared_ptr<Numero> Complejo::operator+ (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es la resta de los operandos
        std::shared_ptr<Numero> Complejo::operator- (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es el producto entre los operandos
        std::shared_ptr<Numero> Complejo::operator* (const Complejo& rhn) const;
        // Devuelve un Complejo cuyo valor es la division de los operandos
        std::shared_ptr<Numero> Complejo::operator/ (const Complejo& rhn) const;

        float getRealPart() const;
        void setRealPart(float value);

        float getImagPart() const;
        void setImagPart(float iValue);

        std::string toString() const;
};
