#pragma once

#include "numero.hpp"

#include <iostream>
#include <format>

class Entero : public Numero{
    private:
        int valor;
    public:
        Entero(int valor = 0);

        Numero* operator+ (const Numero* rhn) const override;
        Numero* operator- (const Numero* rhn) const override;
        Numero* operator* (const Numero* rhn) const override;
        
        std::string toString() const override;

        int getValor() const;
};