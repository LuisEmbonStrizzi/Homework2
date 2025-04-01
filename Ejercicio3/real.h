#pragma once
#include "numero.h"

using namespace std;
class Real : public Numero {
private:
    double valor;
public:
    Real(double v);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    string toString() const override;

    double getValor() const;
};

