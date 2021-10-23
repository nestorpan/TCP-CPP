#include "Persona.h"
#include "PersonaException.h"

/*
Persona::Persona()
: dni(1L), sexo('X')
{
    //this->dni = 1L;
    //this->sexo = 'X';
}
*/

Persona::Persona(int dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac)
//: dni(dni), apellido(apellido), nombre(nombre), sexo(sexo), fNac(fNac)
{
//	this->apellido = apellido;

	setDni(dni);
	setApellido(apellido);
	setNombre(nombre);
	setSexo(sexo);
	setFNac(fNac);
}

void Persona::setDni(int dni)
{
	if(dni < 0)
		throw PersonaException(Cadena("El DNI ") + dni + " es inválido.");

	this->dni = dni;
}


void Persona::setApellido(const Cadena& apellido)
{
	this->apellido = apellido;
//	this->apellido.normalizar();
}


void Persona::setNombre(const Cadena& nombre)
{
	this->nombre = nombre;
//	this->nombre.normalizar();
}


void Persona::setSexo(char sexo)
{
	if(sexo != 'M' && sexo != 'F' && sexo != 'X')
		throw PersonaException(Cadena("El sexo ") + sexo + " es inválido.");

	this->sexo = sexo;
}


void Persona::setFNac(const Fecha& fNac)
{
	if(fNac > Fecha::hoy())
		throw PersonaException(Cadena("La fecha de nacimiento ") + fNac + " es futura.");

	this->fNac = fNac;
}

int Persona::getEdad(const Fecha& fRef) const
{
	return this->fNac.difEnAnios(fRef);
}
