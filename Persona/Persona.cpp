#include "Persona.h"
#include "PersonaException.h"


Persona::Persona()
: dni(0), apyn(), sexo('M'), fNac(), estadoCivil('S')
{
	this->dni = 0;
	
	cout << "Constructor Persona Default" << endl;
}


Persona::Persona(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil)
{
	this->setDni(dni);
	this->setApyn(apyn);
	this->setSexo(sexo);
	this->setFNac(fNac);
	this->setEstadoCivil(estadoCivil);
}


void Persona::setDni(unsigned dni)
{
	if(dni == 0)
		throw PersonaException("El DNI es inválido");
	
	this->dni = dni;
}


unsigned Persona::getDni() const
{
	return this->dni;
}


void Persona::setApyn(const Cadena& apyn)
{
	///TODO: aplicar trim
	
	this->apyn = apyn;
}


const Cadena& Persona::getApyn() const
{
	return this->apyn;
}


void Persona::setSexo(char sexo)
{
	sexo = toupper(sexo);
	
	if(sexo != 'M' && sexo != 'F')
		throw PersonaException("El sexo es inválido");
	
	this->sexo = sexo;
}


char Persona::getSexo() const
{
	return this->sexo;
}


void Persona::setFNac(const Fecha& fNac)
{
	this->fNac = fNac;
}


const Fecha& Persona::getFNac() const
{
	return this->fNac;
}


void Persona::setEstadoCivil(char estadoCivil)
{
	estadoCivil = toupper(estadoCivil);
	this->estadoCivil = estadoCivil;
}


char Persona::getEstadoCivil() const
{
	return this->estadoCivil;
}


ostream& operator <<(ostream& sal, const Persona& p)
{
	return sal << p.dni << '|' << p.apyn << '|' << p.sexo << '|' << p.fNac << '|' << p.estadoCivil;
}


Persona& Persona::operator =(const Persona& otra)
{
	cout << "Persona Operator =" << endl;
	
	this->setDni(otra.dni);
	this->setApyn(otra.apyn);
	this->setSexo(otra.sexo);
	this->setFNac(otra.fNac);
	this->setEstadoCivil(otra.estadoCivil);
	
	return *this;
}
