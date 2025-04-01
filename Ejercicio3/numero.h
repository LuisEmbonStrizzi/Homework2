#pragma once

#include <string>
using namespace std;
class Numero {
public:
    virtual Numero* suma(const Numero& otro) const = 0;
    virtual Numero* resta(const Numero& otro) const = 0;
    virtual Numero* multiplicacion(const Numero& otro) const = 0;
    virtual string toString() const = 0;

    virtual ~Numero() {}
};

