#include "cajaDeAhorro.h"
#include "cuentaCorriente.h"

/*

    La estructura del sistema se basa en una clase abstracta `CuentaBancaria`, que representa una cuenta de banco genérica.
    A partir de esta clase, se han creado dos clases derivadas: `CajaDeAhorro` y `CuentaCorriente`, cada una con su propia 
    lógica para manejar depósitos, retiros y consultas de saldo.

    a)
    Justificación de los especificadores de acceso:
    1. CuentaBancaria (Clase Base)
    - protected:
        - double balance;  
          se usa protected para que las subclases (CajaDeAhorro y CuentaCorriente) puedan acceder a este atributo 
          sin necesidad de métodos getter, pero evitando su modificación desde fuera de la jerarquía.
          
        - string titularCuenta;  
          ídem que balance

    - public:  
        - CuentaBancaria(string titular, double saldoInicial);  
          constructor público para permitir la creación de cuentas bancarias.

        - virtual void depositar(double cantidad);  
          cúblico porque debe ser accesible desde cualquier parte del programa.

        - virtual void retirar(double cantidad) = 0;  
          método virtual puro que obliga a las subclases a definir su propia implementación del retiro de dinero.

        - virtual void mostrarInfo() const = 0;  
          idem que retirar

        - double getBalance() const; y string getTitular() const;  
          métodos getter públicos que permiten acceder de forma segura a los datos privados.

    2. CajaDeAhorro (Clase Derivada de CuentaBancaria)
    - private:  
        - mutable int vecesMostrada = 0;  
          este atributo es privado porque solo debe ser modificado dentro de la propia clase. Se usa mutable para 
          permitir su modificación en métodos const, asegurando que mostrarInfo() pueda modificarlo

    - public:  
        - CajaDeAhorro(string titular, double saldoInicial);  
          constructor público para instanciar cuentas de ahorro.

        - void retirar(double cantidad) override;  
          público para permitir retiros de la cuenta. Se usa override porque sobrescribe el método de la clase base.

        - void mostrarInfo() const override;  
          idem que retirar

    3. CuentaCorriente (Clase Derivada de CuentaBancaria)
    - private:  
        - CajaDeAhorro* cajaAhorro;  
          se mantiene private para garantizar que solo la CuentaCorriente pueda gestionar su cuenta de ahorro asociada.

    - public:  
        - CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* ahorro);  
          constructor público para permitir la creación de cuentas corrientes.

        - void retirar(double cantidad) override;  
          público para permitir retiros de la cuenta. Se usa override porque sobrescribe el método de la clase base.

        - void mostrarInfo() const override;  
          idem que retirar

    - friend void verificarFondos(const CuentaCorriente& cuenta);  
        - Se usa friend para permitir que una función externa acceda a los datos privados de CuentaCorriente sin 
          romper el hecho de que se mantenga encapsulado si se puede decir de alguna manera
*/


int main() {
    CajaDeAhorro miAhorro("Juan Perez", 500);
    CuentaCorriente miCorriente("Juan Perez", 200, &miAhorro);

    miAhorro.mostrarInfo();
    miCorriente.mostrarInfo();

    miCorriente.retirar(300); 
    miAhorro.mostrarInfo();
    miCorriente.mostrarInfo();

    miAhorro.mostrarInfo();
    miAhorro.mostrarInfo();
    miAhorro.mostrarInfo();

    miCorriente.retirar(500);
    verificarFondos(miCorriente);

    return 0;
}
