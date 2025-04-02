#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Real : public Numero {
    private:
        int r_intPart;
        float r_realPart;
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

        // Devuelve un ostream cargado con el valor formateado usando std::format para mostrar correctamente los float.
        friend std::ostream& operator<<(std::ostream& os, const Real& numero);

        int getIntPart() const override;
        float getRealPart() const override;
        
        // Toma un entero, que pasa a ser la parte entera del numero
        void setIntPart(int value) override;
        // Toma un float, y solo queda como parte Real lo que esta luego de la coma.
        void setRealPart(float value) override;
};
