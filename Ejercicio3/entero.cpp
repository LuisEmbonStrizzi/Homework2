#include "entero.h"
#include <sstream>

using namespace std;
Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(const Numero& otro) const {
    const Entero* otroE = dynamic_cast<const Entero*>(&otro);
    return otroE ? new Entero(valor + otroE->valor) : nullptr;
}

Numero* Entero::resta(const Numero& otro) const {
    const Entero* otroE = dynamic_cast<const Entero*>(&otro);
    return otroE ? new Entero(valor - otroE->valor) : nullptr;
}

Numero* Entero::multiplicacion(const Numero& otro) const {
    const Entero* otroE = dynamic_cast<const Entero*>(&otro);
    return otroE ? new Entero(valor * otroE->valor) : nullptr;
}

string Entero::toString() const {
    return to_string(valor);
}

int Entero::getValor() const {
    return valor;
}
