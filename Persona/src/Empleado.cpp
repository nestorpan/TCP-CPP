#include "Empleado.h"


Empleado::Empleado()
: Persona(), fIngr(), sueldo(0)
{}


Empleado::Empleado(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil, const Fecha& fIngr, double sueldo)
: Persona(dni, apyn, sexo, fNac, estadoCivil, "")
{
	this->setFIngr(fIngr);
	this->setSueldo(sueldo);
}

const Fecha& Empleado::getFIngr()
{
	return this->fIngr;
}

void Empleado::setFIngr(const Fecha& fIngr)
{
	///TODO: verificar > fNac
	this->fIngr = fIngr;
}


double Empleado::getSueldo()
{
	return this->sueldo;
}

void Empleado::setSueldo(double sueldo)
{
	this->sueldo = sueldo;
}

int Empleado::getAntiguedad()
{
	return this->fIngr.difEnAnios(Fecha::hoy());
}

ostream& operator <<(ostream& sal, const Empleado& empl);
istream& operator >>(istream& ent, Empleado& empl);
