#pragma once

#include <string>

class CuentaBanco{
    // Son protected porque van a ser heredados, sinó deberian ser private por encapsulamiento
    protected:
        double balance;
        std::string titularCuenta;
    // Son publicos porque luego de ser heredados deberian poder ser usados desde el exterior de la clase.
    public:
        // Le suma a balance del valor depositado
        void depositar(double deposito);
        // Muestra la informacion de la cuenta: balance, tipo de cuenta, nombre del titular
        virtual void mostrarInfo() = 0;

        // Getter para poder verificar funcionalidad.
        double getBalance() const;
        
        virtual bool retirar(double monto) = 0;
};