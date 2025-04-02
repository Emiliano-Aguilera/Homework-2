#pragma once

#include "numero.hpp"

#include <iostream>

class Entero : public Numero{
    private:
        int e_value;
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

        // Devuelve un ostream con el valor cargado para poder usarlo con cout.
        friend std::ostream& operator<<(std::ostream& os, const Entero& numero);
        
        int getIntPart() const override;
        void setIntPart(int value) override;
};