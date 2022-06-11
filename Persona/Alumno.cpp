#include "Alumno.h"


Alumno::Alumno(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo, int cantMatAprob, float promedio)
: Persona(dni, nombre, apellido, fechaNacimiento, sexo), cantMatAprob(cantMatAprob), promedio(promedio)
{}


int Alumno::getCantMatAprob() const
{
    return cantMatAprob;
}


void Alumno::setCantMatAprob(int cantMatAprob)
{
    this->cantMatAprob = cantMatAprob;
}


float Alumno::getPromedio() const
{
    return promedio;
}


void Alumno::setPromedio(float promedio)
{
    this->promedio = promedio;
}
