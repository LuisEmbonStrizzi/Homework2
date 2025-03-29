#include <iostream>
#include <iomanip>
#include "ejercicio1.h"
#include <stdexcept>
#include <sstream>

using namespace std;

/*
    Implementación de la clase DetermineTime
    - Se utiliza sobrecarga de constructores para permitir diferentes formas de inicialización.
    - Se usa lista de inicialización en cada constructor para asignar valores a los atributos de la clase.
*/

// Constructor por defecto, inicializa todo en 0 y "a.m."
DetermineTime::DetermineTime() : hrs(0), mins(0), secs(0), part_day("a.m.") {}

// Constructor que solo recibe la hora
DetermineTime::DetermineTime(int HHh) : hrs(HHh), mins(0), secs(0), part_day("a.m.") {
    if (HHh < 1 || HHh > 12) throw invalid_argument("Horas fuera de rango (1-12).");
}

// Constructor que recibe hora y minutos
DetermineTime::DetermineTime(int HHh, int MMm) : hrs(HHh), mins(MMm), secs(0), part_day("a.m.") {
    if (HHh < 1 || HHh > 12) throw invalid_argument("Horas fuera de rango (1-12).");
    if (MMm < 0 || MMm >= 60) throw invalid_argument("Minutos fuera de rango (0-59).");
}

// Constructor que recibe hora, minutos y segundos
DetermineTime::DetermineTime(int HHh, int MMm, int SSs) : hrs(HHh), mins(MMm), secs(SSs), part_day("a.m.") {
    if (HHh < 1 || HHh > 12) throw invalid_argument("Horas fuera de rango (1-12).");
    if (MMm < 0 || MMm >= 60) throw invalid_argument("Minutos fuera de rango (0-59).");
    if (SSs < 0 || SSs >= 60) throw invalid_argument("Segundos fuera de rango (0-59).");
}

// Constructor completo con AM/PM
DetermineTime::DetermineTime(int HHh, int MMm, int SSs, string AM_PM) : hrs(HHh), mins(MMm), secs(SSs), part_day(AM_PM) {
    if (HHh < 1 || HHh > 12) throw invalid_argument("Horas fuera de rango (1-12).");
    if (MMm < 0 || MMm >= 60) throw invalid_argument("Minutos fuera de rango (0-59).");
    if (SSs < 0 || SSs >= 60) throw invalid_argument("Segundos fuera de rango (0-59).");
    if (AM_PM != "a.m." && AM_PM != "p.m.") throw invalid_argument("Formato incorrecto. Debe ser 'a.m.' o 'p.m.'.");
}

// Métodos para modificar los atributos de la clase
void DetermineTime::setHour(int h) {
    if (h < 1 || h > 12) throw invalid_argument("Horas fuera de rango (1-12).");
    hrs = h;
}

void DetermineTime::setMins(int m) {
    if (m < 0 || m >= 60) throw invalid_argument("Minutos fuera de rango (0-59).");
    mins = m;
}

void DetermineTime::setSecs(int s) {
    if (s < 0 || s >= 60) throw invalid_argument("Segundos fuera de rango (0-59).");
    secs = s;
}

void DetermineTime::setPartOfDay(string part) {
    if (part != "a.m." && part != "p.m.") throw invalid_argument("Formato incorrecto. Debe ser 'a.m.' o 'p.m.'.");
    part_day = part;
}

// Métodos para obtener los valores
int DetermineTime::getHour() const { return hrs; }
int DetermineTime::getMins() const { return mins; }
int DetermineTime::getSecs() const { return secs; }
string DetermineTime::getPartOfDay() const { return part_day; }

// Mostrar la hora en formato HHh, MMm, SSs a.m./p.m.
void DetermineTime::showTime() const {
    cout << setfill('0') << setw(2) << hrs << "h, "
         << setw(2) << mins << "m, "
         << setw(2) << secs << "s "
         << part_day << endl;
}

// Mostrar la hora en formato 24h
void DetermineTime::showTime24h() const {
    int hour24 = hrs;
    if (part_day == "p.m." && hrs != 12) hour24 += 12;
    if (part_day == "a.m." && hrs == 12) hour24 = 0;

    cout << setfill('0') << setw(2) << hour24 << ":"
         << setw(2) << mins << ":"
         << setw(2) << secs << endl;
}

int main() {
    DetermineTime reloj;
    int opcion, h, m, s;
    string am_pm, input;
    stringstream ss;

    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Mostrar tiempo" << endl;
        cout << "2. Mostrar tiempo en formato 24h" << endl;
        cout << "3. Cambiar todo (hora, minutos, segundos, AM/PM)" << endl;
        cout << "4. Cambiar solo la hora" << endl;
        cout << "5. Cambiar solo los minutos" << endl;
        cout << "6. Cambiar solo los segundos" << endl;
        cout << "7. Cambiar solo AM/PM" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                reloj.showTime();
                break;
            case 2:
                reloj.showTime24h();
                break;
            case 3:
                cout << "Ingrese la hora en formato HH MM SS AM/PM (ejemplo: 12 30 45 a.m.): ";
                cin.ignore();
                getline(cin, input);
                ss.clear();
                ss.str(input);
                ss >> h >> m >> s >> am_pm;
                try {
                    reloj.setHour(h);
                    reloj.setMins(m);
                    reloj.setSecs(s);
                    reloj.setPartOfDay(am_pm);
                    cout << "Hora cambiada con éxito!" << endl;
                } catch (const invalid_argument& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 4:
                cout << "Ingrese nueva hora (1-12): ";
                cin >> h;
                try { reloj.setHour(h); } catch (const invalid_argument& e) { cerr << "Error: " << e.what() << endl; }
                break;
            case 5:
                cout << "Ingrese nuevos minutos (0-59): ";
                cin >> m;
                try { reloj.setMins(m); } catch (const invalid_argument& e) { cerr << "Error: " << e.what() << endl; }
                break;
            case 6:
                cout << "Ingrese nuevos segundos (0-59): ";
                cin >> s;
                try { reloj.setSecs(s); } catch (const invalid_argument& e) { cerr << "Error: " << e.what() << endl; }
                break;
            case 7:
                cout << "Ingrese AM/PM (a.m. o p.m.): ";
                cin >> am_pm;
                try { reloj.setPartOfDay(am_pm); } catch (const invalid_argument& e) { cerr << "Error: " << e.what() << endl; }
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 8);
    return 0;
}