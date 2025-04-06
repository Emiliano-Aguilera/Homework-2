#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Real : public Numero{
    private:
        double valor;
    public:
        Real(double value=0);
        
        Numero* operator+ (const Numero* rhn) const override;
        Numero* operator- (const Numero* rhn) const override;
        Numero* operator* (const Numero* rhn) const override;

        std::string toString() const override;

        double getValor() const;
};