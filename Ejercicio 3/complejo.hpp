#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>
#include <memory>

class Complejo : public Numero {
    private:
        double valorReal;
        double valorImag;
    public:
        Complejo(double rValue=0.0, double iValue=0.0);

        Numero* operator+ (const Numero* rhn) const override;
        Numero* operator- (const Numero* rhn) const override;
        Numero* operator* (const Numero* rhn) const override;
        
        std::string toString() const override;

        double getValorReal() const;
        double getValorImag() const;
};
