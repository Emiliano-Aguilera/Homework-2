#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Complejo : public Numero {
    private:
        int c_intPart;
        float c_realPart;
        float c_imagPart;
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

        // Devuelve un ostream con el valor formateado usando std::format porque to_string mostraba incorrectamente los float.
        friend std::ostream& operator<<(std::ostream& os, const Complejo& numero);

        int getIntPart() const override;
        float getRealPart() const override;
        float getImagPart() const override;
        
        // Toma un entero, que pasa a ser la parte entera del numero
        void setIntPart(int value) override;
        // Toma un float, y solo queda como parte Complejo lo que esta luego de la coma.
        void setRealPart(float value) override;
        // Toma un float que pasa a ser la parte imaginaria.
        void setImagPart(float iValue) override;


};
