#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
:
	dni(1),
	apellido(""),
	nombre(""),
	sexo('M'),
	fNac(Fecha(1, 1, 1800))
{}


void PersonaBuilder::setDni(unsigned dni)
{
	this->dni = dni;
}


void PersonaBuilder::setApellido(const Cadena& apellido)
{
	this->apellido = apellido;
}


void PersonaBuilder::setNombre(const Cadena& nombre)
{
	this->nombre = nombre;
}


void PersonaBuilder::setSexo(char sexo)
{
	this->sexo = sexo;
}


void PersonaBuilder::setFNac(const Fecha& fNac)
{
	this->fNac = fNac;
}


Persona PersonaBuilder::build()
{
	return Persona(dni, apellido, nombre, sexo, fNac);
}

