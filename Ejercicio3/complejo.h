#pragma once
#include "numero.h"

using namespace std;
class Complejo : public Numero {
private:
    double real, imaginario;
public:
    Complejo(double r, double i);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    string toString() const override;

    double getReal() const;
    double getImaginario() const;
};

