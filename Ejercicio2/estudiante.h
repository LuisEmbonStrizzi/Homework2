#pragma once
#include <string>
#include <vector>

using namespace std;

class Estudiante {
    private:
        string nombre;
        int legajo;
        vector<pair<string, double>> cursos; // (Nombre del curso, Nota final) decidí hacer vector de tuplas
    
    public:
        Estudiante(string nombre, int legajo);
        string getName() const;
        int getLegajo() const;
        double getPromedio() const;
        void cambiarNombre(const string& nuevoNombre);
        void agregarCurso(const string& curso, double nota);
        void mostrarCursos() const;
        void cambiarNotaCurso(const string& nombreCurso, double nuevaNota);

        double obtenerNotaDeCurso(const string& nombreCurso) const;

        bool operator<(const Estudiante& otro) const;
        friend ostream& operator<<(ostream& os, const Estudiante& estudiante); //Lo declaro como friend para que acceda a los atributos privadoss

};