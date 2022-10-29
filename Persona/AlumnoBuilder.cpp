#include "AlumnoBuilder.h"

AlumnoBuilder::AlumnoBuilder()
: promedio(0), cantMatAprob(0)
{}


Alumno AlumnoBuilder::buildEstatica()
{
	return Alumno(dni, apellido, nombre, fechaNacimiento, carrera, fechaIngreso, promedio, cantMatAprob);
}


Alumno* AlumnoBuilder::buildDinamica()
{
	return new Alumno(dni, apellido, nombre, fechaNacimiento, carrera, fechaIngreso, promedio, cantMatAprob);
}
