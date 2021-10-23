#include "Empleado.h"
#include "PersonaException.h"


Empleado::Empleado(int dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac,
	long legajo, const Cadena& puesto, float sueldo, const Fecha& fIngr)
: Persona(dni, apellido, nombre, sexo, fNac)
{
	setLegajo(legajo);
	setPuesto(puesto);
	setSueldo(sueldo);
	setFIngr(fIngr);
}


long Empleado::getLegajo()
{
	return this->legajo;
}


void Empleado::setLegajo(long legajo)
{
	this->legajo = legajo;
}


const Cadena& Empleado::getPuesto()
{
	return this->puesto;
}


void Empleado::setPuesto(const Cadena& puesto)
{
	this->puesto = puesto;
}


float Empleado::getSueldo()
{
	return this->sueldo;
}


void Empleado::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}


const Fecha& Empleado::getFIngr()
{
	return this->fIngr;
}


void Empleado::setFIngr(const Fecha& fIngr)
{
	if(getFNac() >= fIngr)
		throw PersonaException("La fecha de ingreso es inconsistente con la de nacimiento.");

	if(getEdad(fIngr) < 16)
		throw PersonaException("No tiene la edad suficiente.");

	this->fIngr = fIngr;
}
