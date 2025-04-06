#include "cajadeahorro.hpp"
#include <iostream>
#include <format>

CajaDeAhorro::CajaDeAhorro(std::string nombreTitular, double balanceIncial) {
    balance = balanceIncial;
    titularCuenta = nombreTitular;
}

bool CajaDeAhorro::retirar(double monto) {
    if(monto <= balance) {
        balance -= monto;
        return true;
    } else {
        throw std::invalid_argument("No hay suficiente dinero disponible. Ingrese un monto menor");
    }
}

std::string CajaDeAhorro::getTipoCuenta() const {
    return "Caja de ahorro";
}

void CajaDeAhorro::mostrarInfo() {
    if (contMostrarInfo != 2) {
        std::cout << std::format("- Tipo de cuenta: {}", getTipoCuenta()) << std::endl;
        std::cout << std::format("- Nombre del titular: {}", titularCuenta) << std::endl;
        std::cout << std::format("- Balance: {}", balance) << std::endl;
    } else {
        if (balance >= 20) {
            std::cout << "Se mostró informacion mas de 2 veces, descontando 20 del balance." << std::endl;
            balance -= 20;
        } else {
            std::cout << "Se mostró informacion mas de 2 veces, no cuenta con el balance suficiente($20)." << std::endl;
            balance = 0;
        }
        
        std::cout << std::format("- Tipo de cuenta: {}", getTipoCuenta()) << std::endl;
        std::cout << std::format("- Nombre del titular: {}", titularCuenta) << std::endl;
        std::cout << std::format("- Balance: {}", balance) << std::endl;
    }
    contMostrarInfo++;
}
