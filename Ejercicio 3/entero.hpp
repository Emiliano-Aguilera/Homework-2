#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Entero : public Numero{
    public:
        Entero(int valor = 0);

        // Devuelve un entero cuyo valor es la suma de los operandos
        Entero operator+ (const Entero& rhn) const;
        // Devuelve un entero cuyo valor es la resta de los operandos
        Entero operator- (const Entero& rhn) const;
        // Devuelve un entero cuyo valor es el producto entre los operandos
        Entero operator* (const Entero& rhn) const;
        // Devuelve un entero cuyo valor es la division de los operandos
        Entero operator/ (const Entero& rhn) const;
        
        // Como Entero no tiene parte imaginaria ni real, sus correspondientes metodos se inhabilitan

        float getRealPart() const = delete;
        float getImagPart() const = delete;

        void setRealPart(float value) = delete;
        void setImagPart(float iValue) = delete;

        std::string toString() const override;
};