#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "estudiante.h"

using namespace std;

class Curso {
private:
    vector<std::shared_ptr<Estudiante>> estudiantes;
    static const size_t CAPACIDAD_MAXIMA = 20;
    string nombre;

public:
    Curso() = default;

    Curso(const Curso& otro) : nombre(otro.nombre), estudiantes(otro.estudiantes) {
        //Justificación de la copia de Curso
        //Tipo de copia: Implementamos una shallow copy en la que los cursos comparten punteros a los mismos objetos Estudiante.

        //Uso de shared_ptr<Estudiante>:

        //Permite que varios cursos compartan referencias a los mismos estudiantes sin duplicar objetos en memoria.

        //Cuando un curso se destruye, los estudiantes permanecen en memoria mientras otros cursos los sigan referenciando.

        //Si un estudiante deja de estar referenciado por cualquier curso, su memoria se libera automáticamente.

        //Inicialmente se consideró el uso de unique_ptr, pero esto generaba problemas 
        //al hacer copias innecesarias de estudiantes. 
        //unique_ptr impide compartir estudiantes entre cursos, lo que hace imposible 
        //representar correctamente la realidad de que un estudiante puede estar inscrito en múltiples cursos.


        //Implementación del constructor de copia:

        //La copia de Curso crea un nuevo vector de shared_ptr<Estudiante>, pero los punteros apuntan a los mismos objetos Estudiante.

        //Esto evita la duplicación innecesaria y permite que las modificaciones a un estudiante en un curso se reflejen en todos los cursos donde esté inscrito.
    }
    //Agregué este método para testear
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
