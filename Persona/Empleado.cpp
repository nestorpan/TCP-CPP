#include "Empleado.h"


Empleado::Empleado()
: Persona(), fIngr(), sueldo(0)
{}


Empleado::Empleado(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil, const Fecha& fIngr, double sueldo)
: Persona(dni, apyn, sexo, fNac, estadoCivil)
{
	this->setFIngr(fIngr);
	this->setSueldo(sueldo);
}


const Fecha& Empleado::getFIngr()
{
	return this->fIngr;
}


void Empleado::setFIngr(const Fecha& fIngr)
{
	///TODO: verificar > fNac
	this->fIngr = fIngr;
}


double Empleado::getSueldo()
{
	return this->sueldo;
}


void Empleado::setSueldo(double sueldo)
{
	this->sueldo = sueldo;
}


int Empleado::getAntiguedad()
{
	return this->fIngr.difEnAnios(Fecha::hoy());
}


void Empleado::write(ofstream& stream) const
{
	this->Persona::write(stream);
	this->fIngr.write(stream);
	stream.write((char*)&this->sueldo, sizeof(double));
}


void Empleado::read(ifstream& stream)
{
	this->Persona::read(stream);
	this->fIngr.read(stream);
	stream.read((char*)&this->sueldo, sizeof(double));
}


ostream& operator <<(ostream& sal, const Empleado& empl)
{
	return sal << (const Persona&)empl << '|' << empl.fIngr << '|' << empl.sueldo;
}


istream& operator >>(istream& ent, Empleado& empl)
{
	ent >> (Persona&)empl;
	
	string campoStr;
	
	/// FIngr
	getline(ent, campoStr, '|');
	empl.fIngr = ((Cadena&)campoStr).toFecha();
	
	/// Sueldo
	getline(ent, campoStr);
	empl.sueldo = stod(campoStr);
	
	ent.ignore(1);
	
	return ent;
}












