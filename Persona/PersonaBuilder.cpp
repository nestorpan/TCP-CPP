#include "PersonaException.h"
#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
: dni(0), apellido()
{}


Persona PersonaBuilder::buildEstatica()
{
	return Persona(dni, apellido, nombre, fechaNacimiento);
}


Persona* PersonaBuilder::buildDinamica()
{
	return new Persona(dni, apellido, nombre, fechaNacimiento);
}
