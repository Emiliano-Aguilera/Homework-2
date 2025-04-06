#pragma once

#include <string>

class CuentaBanco{
    protected:
        double balance;
        std::string titularCuenta;
    public:
        // Le suma a balance del valor depositado
        void depositar(double deposito);
        // Muestra la informacion de la cuenta: balance, tipo de cuenta, nombre del titular
        virtual void mostrarInfo() = 0;

        // Getter para poder verificar funcionalidad.
        double getBalance() const;
        
        virtual bool retirar(double monto) = 0;
};