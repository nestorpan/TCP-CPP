#include "Alumno.h"

Alumno::Alumno()
: promedio(0), cantMatAprob(0)
{}


Alumno::Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob)
: Persona(dni, apellido, nombre, fechaNacimiento), carrera(carrera), fechaIngreso(fechaIngreso), promedio(promedio), cantMatAprob(cantMatAprob)
{}


ostream& operator <<(ostream& os, const Alumno& alumno)
{
    return os << (Persona&)alumno << '\t' << alumno.carrera << '\t' << alumno.fechaIngreso << '\t' << alumno.promedio << '\t' << alumno.cantMatAprob;
}


istream& operator >>(istream& is, Alumno& alumno)
{
    is >> (Persona&)alumno;
    
    char campo[501];

    is.getline(campo, 501, '\t');
    alumno.carrera = (const char*)campo;

    is.getline(campo, 501, '\t');
    alumno.fechaIngreso = Cadena((const char*)campo).toFecha();

    is.getline(campo, 501, '\t');
    alumno.promedio = atof(campo);

    is.getline(campo, 501);
    alumno.cantMatAprob = atoi(campo);

    return is;
}
