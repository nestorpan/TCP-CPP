#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
: dni(0), apyn(), sexo('F'), fNac(), estadoCivil('S'), email()
{}

void PersonaBuilder::setDni(unsigned dni)
{
	this->dni = dni;
}


void PersonaBuilder::setApyn(const Cadena& apyn)
{
	this->apyn = apyn;
}

void PersonaBuilder::setEmail(const Cadena& email)
{
	this->email = email;
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
	return Persona(dni, apyn, sexo, fNac, estadoCivil, email);
}
