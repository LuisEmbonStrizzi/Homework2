#pragma once
#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
protected: 
    double balance;  //lo puse en protected para que solo sea accedido desde las subclases (CajaDeAhorro, CuentaCorriente)
    string titularCuenta; //idem que el anterior

public:
    CuentaBancaria(string titular, double saldoInicial);

    // los defino como método puro, esto obliga que las subclases deban implementarlo
    virtual void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0; 
    virtual void mostrarInfo() const = 0;

    double getBalance() const;
    string getTitular() const;
};

