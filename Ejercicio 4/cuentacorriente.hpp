#pragma once

#include "cuentabanco.hpp"
#include "cajadeahorro.hpp"

class CuentaCorriente: public CuentaBanco{
    private:
        // Caja de Ahorro asociada a la cuenta corriente, para poder retirar dinero.
        CajaDeAhorro* cajaAsociada;
    public:
        // Constructor
        CuentaCorriente(std::string nombreTitular, double balanceInicial, CajaDeAhorro* caja);
        // Muestra la informacion de la cuenta: balance, tipo de cuenta, nombre del titular
        void mostrarInfo() override;
        // Intenta retirar dinero de la cuenta corriente, sino lo logra, intenta retirarlo de la caja de ahorro, si no lo logra, devuelve false.
        bool retirar(double monto) override;
    private:
        std::string getTipoCuenta() const;
};