#pragma once

#include "cuentabanco.hpp"

class CuentaCorriente;

class CajaDeAhorro : public CuentaBanco {
    private:
        int contMostrarInfo = 0;
    public:
        // Constructor. balanceInicial toma por defecto 0.0
        CajaDeAhorro(std::string nombreTitular, double balanceInicial=0.0);
        
        void mostrarInfo() override;
        // Le resta a balance el monto especificado, siempre y cuando balance >= monto, en cuyo caso devuelve true. 
        //De lo contrario devuelve false, y lanza invalid_argument
        bool retirar(double monto) override;
        
        friend class CuentaCorriente;
    private:
        std::string getTipoCuenta() const;
};

