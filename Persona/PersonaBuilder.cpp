#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
: dni(0), apyn(), sexo('M'), fNac(), estadoCivil('S')
{}


void PersonaBuilder::setDni(unsigned dni)
{
	this->dni = dni;
}


void PersonaBuilder::setApyn(const Cadena& apyn)
{
	this->apyn = apyn;
}


void PersonaBuilder::setSexo(char sexo)
{
	this->sexo = sexo;
}


void PersonaBuilder::setFNac(const Fecha& fNac)
{
	this->fNac = fNac;
}


void PersonaBuilder::setEstadoCivil(char estadoCivil)
{
	this->estadoCivil = estadoCivil;
}


Persona PersonaBuilder::build()
{
	return Persona(dni, apyn, sexo, fNac, estadoCivil);
}
