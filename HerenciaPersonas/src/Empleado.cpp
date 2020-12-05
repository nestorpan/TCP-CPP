#include "Empleado.h"


Empleado::Empleado()
{
}


Empleado::Empleado
(
	unsigned dni,
	const Cadena& apellido,
	const Cadena& nombre,
	char sexo,
	const Fecha& fNac,
	unsigned legajo,
	const Fecha& fIngr
)
:	Persona(dni, apellido, nombre, sexo, fNac),
	legajo(legajo),
	fIngr(fIngr)
{
	///TODO: Agregar validaciones legajo, fIngr, sueldo.
}


Empleado::~Empleado()
{}


unsigned Empleado::getLegajo()
{
	return this->legajo;
}


const Fecha& Empleado::getFIngr()
{
	return this->fIngr;
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


ostream& operator <<(ostream& sal, const Empleado& empleado)
{
	return sal << (Persona&)empleado << '|' << empleado.legajo << '|' << empleado.fIngr;
}


istream& operator >>(istream& ent, Empleado& empleado)
{
	ent >> (Persona&)empleado;
	ent.ignore(1);
	ent >> empleado.legajo;
	ent.ignore(1);
	ent >> empleado.fIngr;
	
	return ent;
}
