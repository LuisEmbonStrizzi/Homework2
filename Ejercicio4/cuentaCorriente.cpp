#include "cuentaCorriente.h"

using namespace std;

CuentaCorriente::CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* ahorro) 
    : CuentaBancaria(titular, saldoInicial), cajaAhorro(ahorro) {}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
        cout << "retiro de $" << cantidad << " realizado desde Cuenta Corriente. Su nuevo balance es: $" << balance << endl;
    } else if (cajaAhorro->getBalance() >= cantidad) {
        cajaAhorro->retirar(cantidad);
        cout << "retiro de $" << cantidad << " usando la caja de ahorro." << endl;
    } else {
        cout << "fondos insuficientes en ambas cuentas." << endl;
    }
}

void CuentaCorriente::mostrarInfo() const {
    cout << "cuenta corriente\n";
    cout << "Titular: " << titularCuenta << "\nBalance: $" << balance << endl;
}

void verificarFondos(const CuentaCorriente& cuenta) {
    if (cuenta.balance == 0 && cuenta.cajaAhorro->getBalance() == 0) {
        cout << "MUCHO CUIDADO!: La cuenta de " << cuenta.titularCuenta << " no tiene fondos en ninguna cuenta.\n";
    }
}
