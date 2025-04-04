#pragma once
#include <string>
#include <vector>

using namespace std;

class Estudiante {
    private:
        string nombre;
        int legajo;
        vector<pair<string, double>> cursos; // (nombre del curso, nota final) decidí hacer vector de tuplas
    
    public:
        Estudiante(string nombre, int legajo);
        string getName() const;
        int getLegajo() const;
        double getPromedio() const;
        void cambiarNombre(const string& nuevoNombre); //este método sirve luego para testear el funcionamiento
        void agregarCurso(const string& curso, double nota);
        void mostrarCursos() const;
        void cambiarNotaCurso(const string& nombreCurso, double nuevaNota);

        double obtenerNotaDeCurso(const string& nombreCurso) const;

        bool operator<(const Estudiante& otro) const;
        friend ostream& operator<<(ostream& os, const Estudiante& estudiante); //lo declaro como friend para que acceda a los atributos privadoss

};