#include "Alumno.h"

Alumno::Alumno()
: promedio(0), cantMatAprob(0)
{}


Alumno::Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob)
: Persona(dni, apellido, nombre, fechaNacimiento), carrera(carrera), fechaIngreso(fechaIngreso), promedio(promedio), cantMatAprob(cantMatAprob)
{}
