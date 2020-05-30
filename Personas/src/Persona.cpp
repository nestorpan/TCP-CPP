#include <FechaException.h>
#include "Persona.h"
#include "PersonaException.h"


#define TAM_BUF 501


Persona::Persona(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo)
: dni(dni), apellido(apellido), nombres(nombres), fechaNac(fechaNac), sexo(sexo)
{
	if(dni < 0)
		throw PersonaException(Cadena("DNI ") + dni + " es invalido");
	
	/// TODO: Resto de validaciones
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setDni(int dni)
{
	if(dni < 0)
		throw PersonaException(Cadena("DNI ") + dni + " es invalido");
	
	this->dni = dni;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
int Persona::getDni() const
{
	return this->dni;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setApellido(const Cadena& apellido)
{
	this->apellido = apellido;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
const Cadena& Persona::getApellido() const
{
	return this->apellido;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setNombres(const Cadena& nombres)
{
	this->nombres = nombres;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
const Cadena& Persona::getNombres() const
{
	return this->nombres;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setFechaNac(const Fecha& fechaNac)
{
/**
	if(fechaNac > Fecha::hoy())
		throw FechaException(Cadena("La fecha ") + fechaNac + " es mayor a hoy");
*/	
	this->fechaNac = fechaNac;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
const Fecha& Persona::getFechaNac() const
{
	return this->fechaNac;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setSexo(char sexo)
{
	this->sexo = sexo;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
char Persona::getSexo() const
{
	return this->sexo;
}


ostream& operator <<(ostream& sal, const Persona& p)
{
	sal << p.getDni() << '|' << p.getApellido() << '|' << p.getNombres() << '|' << p.getFechaNac()  << '|' << p.getSexo();
	return sal;
}


istream& operator >>(istream& ent, Persona& p)
{
	char buffer[TAM_BUF];
	
	ent.getline(buffer, TAM_BUF, '|');
	p.setDni(atoi(buffer));
	
	ent.getline(buffer, TAM_BUF, '|');
	p.setApellido((const char*)buffer);
	
	ent.getline(buffer, TAM_BUF, '|');
	p.setNombres((const char*)buffer);
	
	ent.getline(buffer, TAM_BUF, '|');
	p.setFechaNac(buffer);
	
	int posStream = ent.tellg();
	
	ent.getline(buffer, TAM_BUF, '|');
	
	if(ent.fail())
	{
		ent.seekg(posStream, ent.beg);
		ent.getline(buffer, TAM_BUF, '\n');
	}
	
	p.setSexo(buffer[0]);
	
	return ent;
}
