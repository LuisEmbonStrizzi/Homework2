#include "complejo.h"
#include <sstream>

using namespace std;
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

Numero* Complejo::suma(const Numero& otro) const {
    const Complejo* otroC = dynamic_cast<const Complejo*>(&otro);
    return otroC ? new Complejo(real + otroC->real, imaginario + otroC->imaginario) : nullptr;
}

Numero* Complejo::resta(const Numero& otro) const {
    const Complejo* otroC = dynamic_cast<const Complejo*>(&otro);
    return otroC ? new Complejo(real - otroC->real, imaginario - otroC->imaginario) : nullptr;
}

Numero* Complejo::multiplicacion(const Numero& otro) const {
    const Complejo* otroC = dynamic_cast<const Complejo*>(&otro);
    if (otroC) {
        double r = real * otroC->real - imaginario * otroC->imaginario;
        double i = real * otroC->imaginario + imaginario * otroC->real;
        return new Complejo(r, i);
    }
    return nullptr;
}

string Complejo::toString() const {
    return to_string(real) + " + " + to_string(imaginario) + "i";
}

double Complejo::getReal() const { return real; }
double Complejo::getImaginario() const { return imaginario; }
