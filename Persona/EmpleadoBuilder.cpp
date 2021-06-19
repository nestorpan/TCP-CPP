#include "EmpleadoBuilder.h"

EmpleadoBuilder::EmpleadoBuilder()
: fIngr(), sueldo(0)
{}


void EmpleadoBuilder::setfIngr(const Fecha& fIngr)
{
	this->fIngr = fIngr;
}


void EmpleadoBuilder::setSueldo(double sueldo)
{
	this->sueldo = sueldo;
}


Empleado EmpleadoBuilder::build()
{
	return Empleado(dni, apyn, sexo, fNac, estadoCivil, fIngr, sueldo);
}
