#pragma once

#include "cuentabanco.hpp"
#include "cajadeahorro.hpp"

class CuentaCorriente: public CuentaBanco{
    // Se declara como privado porque no se espera que otra clase herede de esta clase. De ser necesario deberia ser protected
    // No se declara como public porque es informacion interna de la clase y se quiere mantener el encapsulamiento.
    private:
        // Caja de Ahorro asociada a la cuenta corriente, para poder retirar dinero.
        CajaDeAhorro* cajaAsociada;
    // Se declaran como public para que puedan ser usados fuera de la clase.
    public:
        // Constructor
        CuentaCorriente(std::string nombreTitular, double balanceInicial, CajaDeAhorro* caja);
        // Muestra la informacion de la cuenta: balance, tipo de cuenta, nombre del titular
        void mostrarInfo() override;
        // Intenta retirar dinero de la cuenta corriente, sino lo logra, intenta retirarlo de la caja de ahorro, si no lo logra, devuelve false.
        bool retirar(double monto) override;
    
    // Se declara como privado ya que se usa solo dentro de la clase, y no se espera que se herede.
    private:
        std::string getTipoCuenta() const;
};