#include "curso.h"
#include "estudiante.h"
#include <iostream>
#include <vector>
using namespace std;

void mostrarMenu() {
    cout << "\n Menu desplegable pedido \n";
    cout << "1. Crear curso\n";
    cout << "2. Inscribir estudiante en curso\n";
    cout << "3. Desinscribir estudiante de curso\n";
    cout << "4. Listar estudiantes de un curso\n";
    cout << "5. Copiar curso\n";
    cout << "6. Ordenar estudiantes de un curso\n";
    cout << "7. Mostrar materias de un estudiante\n";
    cout << "8. Mostrar promedio general de un estudiante\n";
    cout << "9. Cambiar nota final de la materia del estudiante\n";
    cout << "10. Cambiar el nombre del estudiante con el objetivo de luego listar (item 4) y que se vea el nombre cambiado en todos los cursos los cuales forma parte el alumno\n";
    cout << "11. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    vector<Curso> cursos;
    int opcion = 0;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        string nombreCurso, nombreEstudiante, materia;
        int legajo = 0;
        double nota = 0.0;

        switch (opcion) {
            case 1: {
                cout << "Ingrese nombre del curso: ";
                getline(cin, nombreCurso);
                Curso curso;
                cursos.push_back(curso);
                cursos.back().crearCurso(nombreCurso);
                cout << "Curso creado correctamente.\n";
                break;
            }

            case 2: {
                cout << "Ingrese nombre del curso: ";
                getline(cin, nombreCurso);
                for (auto& curso : cursos) {
                    if (curso.getNombre() == nombreCurso) {
                        cout << "Ingrese nombre del estudiante: ";
                        getline(cin, nombreEstudiante);
                        cout << "Ingrese legajo del estudiante: ";
                        cin >> legajo;
                        if (curso.inscribirEstudiante(nombreEstudiante, legajo)) {
                            cout << "Estudiante inscrito correctamente.\n";
                        }
                        break;
                    }
                }
                break;
            }

            case 3: {
                cout << "Ingrese nombre del curso: ";
                getline(cin, nombreCurso);
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
                for (auto& curso : cursos) {
                    if (curso.getNombre() == nombreCurso) {
                        if (curso.desinscribirEstudiante(legajo)) {
                            cout << "Estudiante desinscrito correctamente.\n";
                        } else {
                            cout << "El estudiante no está inscrito en el curso.\n";
                        }
                        break;
                    }
                }
                break;
            }

            case 4: {
                cout << "Ingrese nombre del curso: ";
                string nombreCurso;
                getline(cin, nombreCurso);
            
                bool encontrado = false;
            
                for (const auto& curso : cursos) {
                    if (curso.getNombre() == nombreCurso) {
                        cout << "Estudiantes en el curso '" << nombreCurso << "':\n";
                        for (const auto& est : curso.obtenerEstudiantes()) {
                            // Obtener la nota del estudiante en este curso
                            double notaCurso = est->obtenerNotaDeCurso(nombreCurso);
                            
                            cout << "Nombre: " << est->getName() 
                                 << ", Legajo: " << est->getLegajo() 
                                 << ", Nota en este curso: " << notaCurso << endl;
                        }
                        encontrado = true;
                        break;
                    }
                }
            
                if (!encontrado) {
                    cout << "Curso '" << nombreCurso << "' no encontrado.\n";
                }
                break;
            }
            

            case 5: {
                cout << "Ingrese nombre del curso a copiar: ";
                getline(cin, nombreCurso);
            
                bool encontrado = false;
            
                for (auto& curso : cursos) { 
                    if (curso.getNombre() == nombreCurso) {
                        string nuevoNombreCurso;
                        cout << "Ingrese nombre para el nuevo curso: ";
                        getline(cin, nuevoNombreCurso);
            
                        Curso nuevoCurso = curso;  //Acá se hace la copia, o sea la shallow copy en este caso
                        nuevoCurso.crearCurso(nuevoNombreCurso);  // Cambia el nombre del curso copiado
            
                        //Acá me aseguro que cada estudiante agregue el nuevo curso a su lista de materias
                        for (auto& estudiante : nuevoCurso.obtenerEstudiantes()) {
                            estudiante->agregarCurso(nuevoNombreCurso, 0.0); 
                        }
            
                        cursos.push_back(nuevoCurso);
                        cout << "Curso copiado correctamente como '" << nuevoNombreCurso << "'.\n";
            
                        // Comprobación inmediata: muestro los estudiantes del curso copiado
                        cout << "Estudiantes en el curso copiado:\n";
                        nuevoCurso.imprimirEstudiantes();  
            
                        encontrado = true;
                        break;
                    }
                }
            
                if (!encontrado) {
                    cout << "Curso '" << nombreCurso << "' no encontrado.\n";
                }
            
                break;
            }
                  
            
            

            case 6: {
                cout << "Ingrese nombre del curso: ";
                getline(cin, nombreCurso);
                for (auto& curso : cursos) {
                    if (curso.getNombre() == nombreCurso) {
                        curso.ordenarEstudiantes();
                        cout << "Estudiantes ordenados.\n";
                        break;
                    }
                }
                break;
            }

            case 7: {
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
            
                bool encontrado = false;
            
                for (const auto& curso : cursos) {  // Recorre todos los cursos
                    for (const auto& est : curso.obtenerEstudiantes()) {  // Recorre los estudiantes en el curso
                        if (est->getLegajo() == legajo) {
                            cout << "Cursos del estudiante en '" << curso.getNombre() << "':\n";
                            est->mostrarCursos();
                            encontrado = true;
                        }
                    }
                }
            
                if (!encontrado) {
                    cout << "No se encontró el estudiante con legajo " << legajo << " en ningún curso.\n";
                }
            
                break;
            }
            

            case 8: {
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
            
                shared_ptr<Estudiante> estudiante = nullptr;
            
                // Buscar el estudiante en todos los cursos
                for (const auto& curso : cursos) {
                    for (const auto& est : curso.obtenerEstudiantes()) {
                        if (est->getLegajo() == legajo) {
                            estudiante = est;
                            break;
                        }
                    }
                    if (estudiante) break;
                }
            
                if (estudiante) {
                    cout << "Promedio del estudiante: " << estudiante->getPromedio() << endl;
                } else {
                    cout << "Estudiante no encontrado.\n";
                }
            
                break;
            }
            

            case 9: {
                cout << "Ingrese nombre del curso: ";
                getline(cin, nombreCurso);
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
                cout << "Ingrese nueva nota: ";
                cin >> nota;
                for (auto& curso : cursos) {
                    if (curso.getNombre() == nombreCurso) {
                        for (auto& est : curso.obtenerEstudiantes()) {
                            if (est->getLegajo() == legajo) {
                                est->cambiarNotaCurso(nombreCurso, nota);
                                cout << "Nota actualizada.\n";
                                break;
                            }
                        }
                    }
                }
                break;
            }

            case 10:
            {
                cout << "Ingrese legajo del estudiante a modificar: ";
                int legajo;
                cin >> legajo;
                
                shared_ptr<Estudiante> estudiante = nullptr;
                
                // Buscar al estudiante en cualquier curso
                for (auto& curso : cursos) {  
                    for (auto& est : curso.obtenerEstudiantes()) {
                        if (est->getLegajo() == legajo) {
                            estudiante = est;  
                            break;
                        }
                    }
                    if (estudiante) break;
                }

                if (estudiante) {
                    cout << "Ingrese el nuevo nombre: ";
                    string nuevoNombre;
                    cin.ignore();
                    getline(cin, nuevoNombre);
                    
                    estudiante->cambiarNombre(nuevoNombre);
                    cout << "Nombre cambiado correctamente.\n";
                } else {
                    cout << "Estudiante no encontrado.\n";
                }

                break;
            }
            case 11:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 11);

    return 0;
}
