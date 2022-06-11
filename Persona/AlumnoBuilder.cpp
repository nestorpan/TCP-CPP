#include "AlumnoBuilder.h"


AlumnoBuilder::AlumnoBuilder()
: PersonaBuilder(), cantMatAprob(0), promedio(0.0)
{}


AlumnoBuilder& AlumnoBuilder::setCantMatAprob(int cantMatAprob)
{
    this->cantMatAprob = cantMatAprob;
    return *this;
}


AlumnoBuilder& AlumnoBuilder::setPromedio(float promedio)
{
    this->promedio = promedio;
    return *this;
}


Alumno AlumnoBuilder::build()
{
    return Alumno(dni, nombre, apellido, fechaNacimiento, sexo, cantMatAprob, promedio);
}
