#include "PersonaException.h"
#include "Persona.h"


Persona::Persona(int dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac)
//: dni(dni), apellido(apellido), nombre(nombre), sexo(sexo), fNac(fNac)
{
	cout << "Se invocó al constructor parametrizado" << endl;
	
	setDni(dni);
	setApellido(apellido);
	setNombre(nombre);
	setSexo(sexo);
	setFNac(fNac);
}


/*
int Persona::getDni() const
{
	return this->dni;
}


const Cadena& Persona::getApellido() const
{
	return this->apellido;
}


const Cadena& Persona::getNombre() const
{
	return this->nombre;
}


char Persona::getSexo() const
{
	return this->sexo;
}


const Fecha& Persona::getFNac() const
{
	return this->fNac;
}
*/

void Persona::setDni(int dni)
{
	if(dni < 0)
		throw PersonaException(Cadena("El DNI ") + dni + " es inv�lido.");
	
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
		throw PersonaException(Cadena("El sexo ") + sexo + " es inv�lido.");
	
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
