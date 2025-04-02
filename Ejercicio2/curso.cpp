#include "curso.h"
#include "estudiante.h"
using namespace std;


Curso::Curso(const Curso& otro) : nombre(otro.nombre), estudiantes(otro.estudiantes) {}

vector<shared_ptr<Estudiante>> Curso::obtenerEstudiantes() const {
    return estudiantes;  // Retorna una copia del vector
}



void Curso::crearCurso(string n) {
    nombre = n;
}

string Curso::getNombre() const {
    return nombre;
}

bool Curso::inscribirEstudiante(string nombre, int legajo) {
    if (cursoCompleto()) {
        cout << "No se puede inscribir. Curso lleno." << endl;
        return false;
    }
    if (estaInscrito(legajo)) {
        cout << "El estudiante ya está inscrito." << endl;
        return false;
    }

    auto estudiante = make_shared<Estudiante>(nombre, legajo);
    
    // Agregar el curso con una nota inicial de 0.0, tiene sentido que arranque con nota 0
    estudiante->agregarCurso(this->getNombre(), 0.0);

    estudiantes.push_back(estudiante);
    
    return true;
}


bool Curso::desinscribirEstudiante(int legajo) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if ((*it)->getLegajo() == legajo) {
            estudiantes.erase(it);
            return true;
        }
    }
    return false;
}

bool Curso::estaInscrito(int legajo) const {
    for (const auto& estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::cursoCompleto() const {
    return estudiantes.size() >= CAPACIDAD_MAXIMA;
}

void Curso::ordenarEstudiantes() {
    sort(estudiantes.begin(), estudiantes.end(), 
         [](const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b) {
             return *a < *b;
         });
}

void Curso::imprimirEstudiantes() const {
    for (const auto& estudiante : estudiantes) {
        cout << *estudiante << endl;
    }
}