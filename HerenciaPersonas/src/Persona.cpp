#include <Defs.h>
#include "Validaciones.h"
#include "Persona.h"


Persona::Persona()
{}


Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac)
:
	dni(dni),
	apellido(apellido),
	nombre(nombre),
	sexo(sexo),
	fNac(fNac)
{
	Validaciones::mayorACero(dni, "DNI invalido");
	
	Validaciones::letrasYEspacios(apellido, "Apellido invalido");
	
	Validaciones::letrasYEspacios(nombre, "Nombre invalido");
	
	Validaciones::sexo(sexo, "Sexo invalido");
	
	Validaciones::fechaMayorIgual(fNac, Fecha(1, 1, 1800), "Fecha Nac. muy antigua");
	Validaciones::fechaMenorIgual(fNac, Fecha::hoy(), "Fecha Nac. futura");
}


unsigned Persona::getDni() const
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


void Persona::setDni(unsigned dni)
{
	Validaciones::mayorACero(dni, "DNI invalido");
	this->dni = dni;
}


void Persona::setApellido(const Cadena& apellido)
{
	this->apellido = apellido;
}


void Persona::setNombre(const Cadena& nombre)
{
	this->nombre = nombre;
}


void Persona::setSexo(char sexo)
{
	this->sexo = sexo;
}


void Persona::setFNac(const Fecha& fNac)
{
	this->fNac = fNac;
}


ostream& operator <<(ostream& sal, const Persona& pers)
{
	return sal << pers.dni << '|' << pers.apellido << '|' << pers.nombre << '|' << pers.sexo << '|' << pers.fNac;
}


istream& operator >>(istream& ent, Persona& pers)
{
	ent >> pers.dni;
	ent.ignore(1);
	pers.apellido.leer(ent, '|');
	pers.nombre.leer(ent, '|');
	ent >> pers.sexo;
	ent.ignore(1);
	ent >> pers.fNac;
	
	return ent;
}















