/*
Este programa implementa una jerarquía de clases basada en la interfaz "Numero".
Utiliza herencia para representar diferentes tipos de números: Entero, Real y Complejo,
cada uno con sus propias implementaciones de suma, resta y multiplicación.

--- DISEÑO ---
1. La clase abstracta "Numero" define la interfaz común con métodos virtuales puros.
2. Las clases "Entero", "Real" y "Complejo" heredan de "Numero" e implementan sus propias
   versiones de las operaciones aritméticas y "toString".
3. El uso de "virtual" en "Numero" permite el polimorfismo, asegurando que las funciones
   de las clases derivadas sean llamadas correctamente cuando se usan punteros a "Numero".
4. "override" indica que un método sobrescribe uno de la clase base, evitando errores.
5. "dynamic_cast" se usa para convertir correctamente referencias a tipos específicos
   cuando se realizan operaciones entre números del mismo tipo.
*/

#include <iostream>
#include "entero.h"
#include "real.h"
#include "complejo.h"

using namespace std;

int main() {
    Entero e1(5), e2(3);
    Numero* resultado = e1.suma(e2);
    cout << "Suma de enteros: " << resultado->toString() << endl;
    delete resultado;

    resultado = e1.resta(e2);
    cout << "Resta de enteros: " << resultado->toString() << endl;
    delete resultado;

    resultado = e1.multiplicacion(e2);
    cout << "Multiplicacion de enteros: " << resultado->toString() << endl;
    delete resultado;

    // Pruebas con números reales
    Real r1(2.5), r2(1.2);
    resultado = r1.suma(r2);
    cout << "Suma de reales: " << resultado->toString() << endl;
    delete resultado;

    resultado = r1.resta(r2);
    cout << "Resta de reales: " << resultado->toString() << endl;
    delete resultado;

    resultado = r1.multiplicacion(r2);
    cout << "Multiplicacion de reales: " << resultado->toString() << endl;
    delete resultado;

    // Pruebas con números complejos
    Complejo c1(1, 2), c2(3, 4);
    resultado = c1.suma(c2);
    cout << "Suma de complejos: " << resultado->toString() << endl;
    delete resultado;

    resultado = c1.resta(c2);
    cout << "Resta de complejos: " << resultado->toString() << endl;
    delete resultado;

    resultado = c1.multiplicacion(c2);
    cout << "Multiplicacion de complejos: " << resultado->toString() << endl;
    delete resultado;

    return 0;
}
