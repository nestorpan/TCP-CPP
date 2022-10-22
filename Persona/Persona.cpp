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
	Cadena linea;

	is >> linea;

	vector<Cadena> campos = linea.split('\t');

	persona.dni = Persona::validarDni(campos[0].toUnsigned());
	persona.apellido = Persona::validarApellido(campos[1]);
	persona.nombre = Persona::validarNombre(campos[2]);
	persona.fechaNacimiento = campos[3].toFecha();
	
	return is;
}
