#pragma once

#include "cuentaBancaria.h"

using namespace std;
class CajaDeAhorro : public CuentaBancaria {
private:
    mutable int vecesMostrada = 0;  //lo puse privado para que solo la clase puede modificarlo con el objetivo de mantener la seguridad

public:
    CajaDeAhorro(string titular, double saldoInicial);

    void retirar(double cantidad) override; //uso override porque estoy trabajando con clases abstractas y override me permite sobreescribir los metodos por los de la clase derivada
    void mostrarInfo() const override;
};

