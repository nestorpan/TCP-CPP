#include "Persona.h"
#include "PersonaException.h"


Persona::Persona()
: dni(0), apyn(), sexo('M'), fNac(), estadoCivil('S')
{
}


Persona::Persona(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil, Cadena email)
{
    this->setDni(dni);
	this->setApyn(apyn);
	this->setSexo(sexo);
	this->setFNac(fNac);
	this->setEstadoCivil(estadoCivil);

	this->email = email;
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

int Persona::getEdad()
{
	return this->fNac.difEnAnios(Fecha::hoy());
}

ostream& operator <<(ostream& sal, const Persona& p)
{
	return sal << p.dni << '|' << p.apyn << '|' << p.sexo << '|' << p.fNac << '|' << p.estadoCivil << '|' << p.email;
}

istream& operator >>(istream& ent, Persona& p)
{
	Cadena linea;
	ent >> linea;

	vector<Cadena> campos = linea.split('|');

	p.dni = campos[0].toUnsigned();
	p.apyn = campos[1];
	p.sexo = campos[2][0];
	p.fNac = campos[3].toFecha();
	p.estadoCivil = campos[4][0];

	return ent;
}

/*
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
*/
