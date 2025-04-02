#include "cajaDeAhorro.h"
#include "cuentaCorriente.h"

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
