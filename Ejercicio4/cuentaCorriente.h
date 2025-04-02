#pragma once
#include "cuentaBancaria.h"
#include "cajaDeAhorro.h"

using namespace std;

class CuentaCorriente : public CuentaBancaria {
private:
    CajaDeAhorro* cajaAhorro;  // lo puse private por motivos de seguridad

public:
    CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* ahorro);

    void retirar(double cantidad) override;
    void mostrarInfo() const override;

    //lo puse friend para acceder a datos privados sin violar encapsulación
    friend void verificarFondos(const CuentaCorriente& cuenta);
};

