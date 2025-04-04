#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "estudiante.h"

using namespace std;

class Curso {
private:
    vector<shared_ptr<Estudiante>> estudiantes;
    static const size_t CAPACIDAD_MAXIMA = 20;
    string nombre;

public:
    Curso() = default;

    Curso(const Curso& otro);
    //Justificación de la copia de Curso
        //El tipo de copia que implementé fue una shallow copy en la que los cursos comparten punteros a los mismos objetos Estudiante.
        //También usé shared_ptr<Estudiante>:
        //Esto me permite que varios cursos compartan referencias a los mismos estudiantes sin duplicar objetos en memoria.
        //Cuando un curso se destruye, los estudiantes permanecen en memoria mientras otros cursos los sigan referenciando.
        //Si un estudiante deja de estar referenciado por cualquier curso, su memoria se libera automáticamente.
        //Inicialmente consideré el uso de unique_ptr, pero esto generaba problemas al hacer copias innecesarias de estudiantes. 
        //unique_ptr impide compartir estudiantes entre cursos, lo que me hacía ruido representar correctamente la realidad de que un estudiante puede estar inscrito en múltiples cursos.
        //En cuanto al constructor de copia: lo que hace es crear un nuevo vector de shared_ptr<Estudiante>, 
        //pero los punteros apuntan a los mismos objetos Estudiante.
        //Esto evita la duplicación innecesaria y permite que las modificaciones a un estudiante en un curso se reflejen en todos los cursos donde esté inscrito.

    vector<shared_ptr<Estudiante>> obtenerEstudiantes() const;
    void crearCurso(string n);
    string getNombre() const;
    bool inscribirEstudiante(string nombre, int legajo);
    bool desinscribirEstudiante(int legajo);
    bool estaInscrito(int legajo) const;
    bool cursoCompleto() const;
    void ordenarEstudiantes();
    void imprimirEstudiantes() const;
};
