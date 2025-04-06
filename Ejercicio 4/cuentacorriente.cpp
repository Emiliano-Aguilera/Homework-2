#include "cuentacorriente.hpp"

#include <string>
#include <iostream>
#include <format>

CuentaCorriente::CuentaCorriente(std::string nombreTitular, double balanceInicial, CajaDeAhorro* caja) {
    titularCuenta = nombreTitular;
    balance = balanceInicial;
    cajaAsociada = caja;
}

void CuentaCorriente::mostrarInfo() {
    std::cout << std::format("- Tipo de cuenta: {}", getTipoCuenta()) << std::endl;
    std::cout << std::format("- Nombre del titular: {}", titularCuenta) << std::endl;
    std::cout << std::format("- Balance: {}", balance) << std::endl;
    
}

std::string CuentaCorriente::getTipoCuenta() const {
    return "Cuenta corriente";
}

bool CuentaCorriente::retirar(double monto) {
    if (monto > balance) {
        if (cajaAsociada->balance >= monto - balance) {
            std::cout << std::format("Se retiro {} de la cuenta corriente, y {} de la caja de ahorro", balance, monto - balance) << std::endl;
            cajaAsociada->balance -= monto - balance;
            balance = 0;
            return true;
        } 
        else {
            std::cout << "No hay dinero disponible ni en la cuenta corriente ni en la caja de ahorro." << std::endl; 
            return false;
        }
    } 
    else {
        balance -= monto;
        return true;
    }
}