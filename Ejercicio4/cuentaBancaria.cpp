#include "cuentaBancaria.h"

using namespace std;
CuentaBancaria::CuentaBancaria(string titular, double saldoInicial) 
    : titularCuenta(titular), balance(saldoInicial) {}

void CuentaBancaria::depositar(double cantidad) {
    if (cantidad > 0) {
        balance += cantidad;
        cout << "depósito de $" << cantidad << " realizado. Su nuevo balance es: $" << balance << endl;
    } else {
        cout << "cantidad inválida para depositar." << endl;
    }
}

double CuentaBancaria::getBalance() const {
    return balance;
}

string CuentaBancaria::getTitular() const {
    return titularCuenta;
}
