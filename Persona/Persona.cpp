#include <iostream>
#include "PersonaException.h"
#include "Persona.h"

using namespace std;


Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento)
: dni(dni), apellido(apellido), nombre(nombre), fechaNacimiento(fechaNacimiento)
{
	cout << "Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento)" << endl;
}

/*
Persona::Persona()
{
	cout << "Persona()" << endl;
}


Persona::Persona(const Persona& persona)
{
	cout << "Persona::Persona(const Persona& persona)" << endl;
}


Persona& Persona::operator =(const Persona& persona)
{
	cout << "Persona& Persona::operator =(const Persona& persona)" << endl;

	this->dni = persona.dni;
	this->apellido = persona.apellido;
	this->nombre = persona.nombre;
	this->fechaNacimiento = persona.fechaNacimiento;

	return *this;
}
*/

unsigned Persona::validarDni(unsigned dni)
{
	if(dni < 10000)
		throw PersonaException("El DNI debe tener al menos 5 dígitos.");

	return dni;
}


const Cadena& Persona::validarApellido(const Cadena& apellido)
{
	return apellido;
}


const Cadena& Persona::validarNombre(const Cadena& nombre)
{
	return nombre;
}
