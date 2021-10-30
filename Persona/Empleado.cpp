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


long Empleado::getLegajo() const
{
	return this->legajo;
}


void Empleado::setLegajo(long legajo)
{
	this->legajo = legajo;
}


const Cadena& Empleado::getPuesto() const
{
	return this->puesto;
}


void Empleado::setPuesto(const Cadena& puesto)
{
	this->puesto = puesto;
}


float Empleado::getSueldo() const
{
	return this->sueldo;
}


void Empleado::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}


const Fecha& Empleado::getFIngr() const
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

ostream& operator <<(ostream& sal, const Empleado& e)
{
	return sal << (Persona&)e << '|' << e.getLegajo() << '|' << e.getPuesto() << '|' << e.getSueldo() << '|' << e.getFIngr();
}

istream& operator >>(istream& ent, Empleado& e)
{
	char c;
	string campoStr;

	ent >> (Persona&)e >> c;
	ent >> e.legajo >> c;

	getline(ent, campoStr, '|');
	e.puesto = campoStr;

	ent >> e.sueldo >> c;

	ent >> e.fIngr;

	ent.ignore(1); // Ignora salto de línea

	return ent;
}
