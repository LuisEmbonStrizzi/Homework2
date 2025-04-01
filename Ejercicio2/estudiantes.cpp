#include <vector>
#include <iostream>
#include "estudiante.h"
using namespace std;

Estudiante::Estudiante(string nombre, int legajo) : nombre(move(nombre)), legajo(legajo) {}

string Estudiante::getName() const {
    return nombre;
}

int Estudiante::getLegajo() const {
    return legajo;
}

void Estudiante::cambiarNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}


void Estudiante::agregarCurso(const string& curso, double nota) {
    cursos.push_back(make_pair(curso, nota));
}

// Método para mostrar los cursos y sus notas
void Estudiante::mostrarCursos() const {
    for (const auto& curso : cursos) {
        cout << "Curso: " << curso.first << ", Nota final: " << curso.second << endl;
    }
}

double Estudiante::getPromedio() const {
    if (cursos.empty()) return 0.0;

    double suma = 0.0;
    for (size_t i = 0; i < cursos.size(); i++) {
        suma += cursos[i].second; // accedo al segundo que es la nota
    }

    return suma / cursos.size();
}

void Estudiante::cambiarNotaCurso(const string& nombreCurso, double nuevaNota) {
    for (auto& curso : cursos) { 
        if (curso.first == nombreCurso) { 
            curso.second = nuevaNota; // Modifica la nota de la materia
            return;
        }
    }
    cout << "Curso no encontrado para este estudiante.\n";
}

double Estudiante::obtenerNotaDeCurso(const string& nombreCurso) const {
    for (const auto& curso : cursos) {
        if (curso.first == nombreCurso) {
            return curso.second;  // Retorna la nota específica de este curso
        }
    }
    return 0.0;  // Si no está inscrito en ese curso, retorna 0
}


bool Estudiante::operator<(const Estudiante& otro) const {
    return nombre < otro.nombre;
}

ostream& operator<<(ostream& os, const Estudiante& estudiante) {
    os << "Nombre: " << estudiante.nombre 
       << ", Legajo: " << estudiante.legajo 
       << ", Promedio: " << estudiante.getPromedio();
    return os;
}