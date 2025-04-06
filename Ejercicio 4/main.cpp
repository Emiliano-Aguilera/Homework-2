#include <iostream>
#include <cassert>
#include "cajadeahorro.hpp"
#include "cuentacorriente.hpp"

using namespace std;

int main() {
    double balanceAhorro = 100;
    double balanceCorriente = 50;

    // Crear una Caja de Ahorro con un balance inicial de 100
    CajaDeAhorro cajaDeAhorro("Juan Perez", balanceAhorro);
    // Crear una Cuenta Corriente asociada a la Caja de Ahorro con un balance inicial de 50
    CuentaCorriente cuentaCorriente("Juan Perez", balanceCorriente, &cajaDeAhorro);

    try{
        // Mostrar información de la Caja de Ahorro 3 veces para testear que se descuenta 20.
        cout << "Test mostrar informacion de la caja de ahorro mas de 2 veces." << std::endl;
        cajaDeAhorro.mostrarInfo();
        cout << endl;
        cajaDeAhorro.mostrarInfo();
        cout << endl;
        cajaDeAhorro.mostrarInfo(); // Esto debería descontar $20 del balance
        cout << endl; 
        balanceAhorro -= 20;
    
        assert(cajaDeAhorro.getBalance() == balanceAhorro); // Verificar que el balance sea correcto
    
        // Mostrar información de la Cuenta Corriente
        cout << endl << "Información de la Cuenta Corriente:" << std::endl;
        cuentaCorriente.mostrarInfo();
    
        // Intentar retirar $30 de la Cuenta Corriente
        double montoRetirado = 30.0;
        balanceCorriente -= montoRetirado;
    
        cout << endl << "Test retirar monto menor al balance de la cuenta corriente.";
        cout << endl << "Intentando retirar $" << montoRetirado << " de la Cuenta Corriente:" << std::endl;
        assert(cuentaCorriente.retirar(montoRetirado) == true); // Verificar que el retiro sea exitoso
        cuentaCorriente.mostrarInfo();
        assert(cuentaCorriente.getBalance() == balanceCorriente); // Verificar que el balance sea correcto
    
        // Intentar retirar $100 de la Cuenta Corriente (debería retirar el total de la caja de ahorro, y el resto de la corriente)
        montoRetirado = 100.0;
        balanceAhorro -= montoRetirado - balanceCorriente;
        balanceCorriente = 0;
    
        cout << endl << "Test retirar de la cuenta corriente, pero haciendo que retire tambien de la caja de ahorro.";
        cout << endl << "Intentando retirar $" << montoRetirado << " de la Cuenta Corriente:" << std::endl;
        assert(cuentaCorriente.retirar(montoRetirado) == true); // Verificar que el retiro sea exitoso
        cuentaCorriente.mostrarInfo();
        cout << endl;
        cajaDeAhorro.mostrarInfo();
        assert(cuentaCorriente.getBalance() == balanceCorriente); // Balance de la cuenta corriente no cambia
        assert(cajaDeAhorro.getBalance() == balanceAhorro); // Verificar que el balance de la caja de ahorro sea correcto
    
        
    
        // Intentar retirar $200 (debería fallar porque no hay suficiente dinero en ambas cuentas)
        montoRetirado = 200.0;
        cout << endl << "Test retirar de la cuenta corriente, pero sin que pueda retirar de la caja de ahorro.";
        cout << endl << "Intentando retirar $" << montoRetirado << " de la Cuenta Corriente:" << std::endl;
        assert(cuentaCorriente.retirar(montoRetirado) == false); // Verificar que el retiro falle
        cuentaCorriente.mostrarInfo();
        assert(cuentaCorriente.getBalance() == balanceCorriente); // Verificar que el balance no cambie
        assert(cajaDeAhorro.getBalance() == balanceAhorro); // Verificar que el balance de la caja de ahorro no cambie
    
        // Depositar $100 en la Caja de Ahorro
        double montoDepositado = 100.0;
        balanceAhorro += montoDepositado;
        
        cout << endl << "Test depositar una cantidad valida.";
        cout << endl << "Depositando $" << montoDepositado << " en la Caja de Ahorro:" << std::endl;
        cajaDeAhorro.depositar(montoDepositado);
        cajaDeAhorro.mostrarInfo();
        assert(cajaDeAhorro.getBalance() == balanceAhorro); // Verificar que el balance sea correcto
        
        // Depositar monto negativo para comprobar el manejo de errores
        montoDepositado = -200.0;
        balanceCorriente = balanceCorriente; // Redundante, pero simboliza que el balance no debe cambiar.
        
        cout << endl << "Test depositar una cantidad invalida.";
        cout << endl << "Depositando $" << montoDepositado << " en la Cuenta Corriente:" << std::endl;
        cuentaCorriente.depositar(montoDepositado);
        cuentaCorriente.mostrarInfo();
        assert(cuentaCorriente.getBalance() == balanceCorriente); // Verificar que el balance sea correcto
    }
    catch (exception& e){
        cerr << e.what() << endl;
    }

    // Mostrar información final de ambas cuentas
    cout << endl << "Información final de la Caja de Ahorro:" << std::endl;
    cajaDeAhorro.mostrarInfo();

    cout << endl << "Información final de la Cuenta Corriente:" << std::endl;
    cuentaCorriente.mostrarInfo();

    cout << endl << endl;

    return 0;   
}