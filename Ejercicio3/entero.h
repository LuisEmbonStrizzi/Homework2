#pragma once
#include "numero.h"

using namespace std;
class Entero : public Numero {
private:
    int valor;
public:
    Entero(int v);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    string toString() const override;

    int getValor() const;
};

