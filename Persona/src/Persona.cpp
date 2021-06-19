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
	string campoStr;

	/// DNI
	getline(ent, campoStr, '|');
	p.dni = stoi(campoStr);

	/// ApYN
	getline(ent, campoStr, '|');
	p.apyn = campoStr;

	p.sexo = ent.get();
	ent.ignore(1); /// Saco el |

	getline(ent, campoStr, '|');
	p.fNac = ((Cadena&)campoStr).toFecha();

	p.estadoCivil = ent.get();
	ent.ignore(1); /// Saco el |

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

void Persona::write(ofstream& stream) const
{
	stream.write((char*)&dni, sizeof(unsigned));
	apyn.write(stream);
	stream.write((char*)&sexo, sizeof(char));
	fNac.write(stream);
	stream.write((char*)&estadoCivil, sizeof(char));
}


void Persona::read(ifstream& stream)
{
	stream.read((char*)&dni, sizeof(unsigned));
	apyn.read(stream);
	stream.read((char*)&sexo, sizeof(char));
	fNac.read(stream);
	stream.read((char*)&estadoCivil, sizeof(char));
}
