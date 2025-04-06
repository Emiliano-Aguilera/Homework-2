#include "cuentabanco.hpp"
#include <stdexcept>

void CuentaBanco::depositar(double deposito) {
    if (deposito >= 0) {
        balance += deposito;
    }
    else {
        throw std::invalid_argument("No puede haber depositos negativos");
    }
}

double CuentaBanco::getBalance() const {
    return balance;
}