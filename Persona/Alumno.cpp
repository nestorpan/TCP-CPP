#include "Alumno.h"

Alumno::Alumno()
//: Persona(), promedio(0), cantMatAprob(0)
: promedio(0), cantMatAprob(0)
{}

/*
Alumno::Alumno(Persona persona, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob)
: Persona(persona->dni, persona->apellido, persona->nombre, persona->fechaNacimiento), carrera(carrera), fechaIngreso(fechaIngreso), promedio(promedio), cantMatAprob(cantMatAprob)
{}
*/

Alumno::Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob)
: Persona(dni, apellido, nombre, fechaNacimiento), carrera(carrera), fechaIngreso(fechaIngreso), promedio(promedio), cantMatAprob(cantMatAprob)
{}
