#include "real.h"
#include <sstream>

Real::Real(double v) : valor(v) {}

using namespace std;

Numero* Real::suma(const Numero& otro) const {
    const Real* otroR = dynamic_cast<const Real*>(&otro);
    return otroR ? new Real(valor + otroR->valor) : nullptr;
}

Numero* Real::resta(const Numero& otro) const {
    const Real* otroR = dynamic_cast<const Real*>(&otro);
    return otroR ? new Real(valor - otroR->valor) : nullptr;
}

Numero* Real::multiplicacion(const Numero& otro) const {
    const Real* otroR = dynamic_cast<const Real*>(&otro);
    return otroR ? new Real(valor * otroR->valor) : nullptr;
}

string Real::toString() const {
    return to_string(valor);
}

double Real::getValor() const {
    return valor;
}
