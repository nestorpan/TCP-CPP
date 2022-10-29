#include <iostream>
#include "../Cadena/Cadena.h"
#include "PersonaException.h"
#include "Persona.h"

using namespace std;


Persona::Persona()
: dni(0)
{}


Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento)
: dni(dni), apellido(apellido), nombre(nombre), fechaNacimiento(fechaNacimiento)
{
	cout << "Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento)" << endl;
}


// Persona::Persona()
// {
// 	cout << "Persona()" << endl;
// }


// Persona::Persona(const Persona& persona)
// {
// 	cout << "Persona::Persona(const Persona& persona)" << endl;
// }


// Persona& Persona::operator =(const Persona& persona)
// {
// 	cout << "Persona& Persona::operator =(const Persona& persona)" << endl;

// 	this->dni = persona.dni;
// 	this->apellido = persona.apellido;
// 	this->nombre = persona.nombre;
// 	this->fechaNacimiento = persona.fechaNacimiento;

// 	return *this;
// }


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


ostream& operator <<(ostream& os, const Persona& persona)
{
	return os << persona.dni << "\t" << persona.apellido << "\t" << persona.nombre << "\t" << persona.fechaNacimiento;
}


istream& operator >>(istream& is, Persona& persona)
{
    char campo[501];

	is.getline(campo, 501, '\t');
	persona.dni = Persona::validarDni(atoi(campo));

	is.getline(campo, 501, '\t');
	persona.apellido = Persona::validarApellido(Cadena((const char*)campo));

	is.getline(campo, 501, '\t');
	persona.nombre = Persona::validarNombre(Cadena((const char*)campo));

	is.getline(campo, 501, '\t');
	persona.fechaNacimiento = Cadena((const char*)campo).toFecha();

	return is;
}
