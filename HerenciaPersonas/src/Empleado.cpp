#include "Empleado.h"


Empleado::Empleado
(
	unsigned dni,
	const Cadena& apellido,
	const Cadena& nombre,
	char sexo,
	const Fecha& fNac,
	unsigned legajo,
	const Fecha& fIngr,
	float sueldo
)
:	Persona(dni, apellido, nombre, sexo, fNac),
	legajo(legajo),
	fIngr(fIngr),
	sueldo(sueldo)
{
	///TODO: Agregar validaciones legajo, fIngr, sueldo.
}


unsigned Empleado::getLegajo()
{
	return this->legajo;
}


const Fecha& Empleado::getFIngr()
{
	return this->fIngr;
}


float Empleado::getSueldo()
{
	return this->sueldo;
}


void Empleado::setLegajo(unsigned legajo)
{
	///TODO: Validar
	this->legajo = legajo;
}


void Empleado::setFIngr(const Fecha& fIngr)
{
	this->fIngr = fIngr;
}


void Empleado::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}


ostream& operator <<(ostream& sal, const Empleado& empleado)
{
	return sal << (Persona&)empleado << '|' << empleado.legajo << '|' << empleado.fIngr << '|' << empleado.sueldo;
}


istream& operator >>(istream& ent, Empleado& empleado)
{
	ent >> (Persona&)empleado;
	ent.ignore(1);
	ent >> empleado.legajo;
	ent.ignore(1);
	ent >> empleado.fIngr;
	ent.ignore(1);
	ent >> empleado.sueldo;
	
	return ent;
}
