#include "cajaDeAhorro.h"

using namespace std;

CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial) 
    : CuentaBancaria(titular, saldoInicial) {}

void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad > balance) {
        cout << "fondos insuficientes por lo que no se puede retirar $" << cantidad << endl;
    } else {
        balance -= cantidad;
        cout << "retiro de $" << cantidad << " realizado. Su nuevo balance es: $" << balance << endl;
    }
}

void CajaDeAhorro::mostrarInfo() const {
    cout << "Caja de Ahorro\n";
    cout << "Titular: " << titularCuenta << "\nBalance: $" << balance << endl;
    vecesMostrada++;
    if (vecesMostrada > 2) {
        cout << "Se descontaron $20 por visualizar la información más de dos veces." << endl;
        const_cast<CajaDeAhorro*>(this)->balance -= 20; 
        // acá tuve problemas y busqué y encontré const_cast, lo usé porque balance es un atributo de la clase y 
        // el método mostrarInfo() está definido como const, lo que impide modificar 
        // cualquier atributo del objeto. Como balance no es mutable (porque representa 
        // dinero real (esto fue una decisión de diseño mía) y no debería modificarse arbitrariamente en métodos const), 
        // la única forma segura de modificarlo en este contexto es utilizando const_cast. 
        // Esto nos permite modificar balance solo en este caso puntual, sin comprometer 
        // la seguridad y coherencia del diseño.
        //https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
        //https://stackoverflow.com/questions/19554841/how-to-use-const-cast
    }
}
