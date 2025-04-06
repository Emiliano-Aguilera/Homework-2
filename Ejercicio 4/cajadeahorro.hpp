#pragma once

#include "cuentabanco.hpp"

class CuentaCorriente;

class CajaDeAhorro : public CuentaBanco {
    // Se declara como privado porque no se espera que otra clase herede de esta clase. De ser necesario deberia ser protected
    // No se declara como public porque es informacion interna de la clase y se quiere mantener el encapsulamiento.
    private:
        int contMostrarInfo = 0;
    // Se declaran como public para que puedan ser usados fuera de la clase.
    public:
        // Constructor. balanceInicial toma por defecto 0.0
        CajaDeAhorro(std::string nombreTitular, double balanceInicial=0.0);
        
        void mostrarInfo() override;
        // Le resta a balance el monto especificado, siempre y cuando balance >= monto, en cuyo caso devuelve true. 
        //De lo contrario devuelve false, y lanza invalid_argument
        bool retirar(double monto) override;
        
        friend class CuentaCorriente;

    // Se declara como privado ya que solo se usa dentro de la clase y no se espera que se herede.
    private:
        std::string getTipoCuenta() const;
};

