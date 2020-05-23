#include "Persona.h"


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
void Persona::setDni(dni)
{
	if(dni < 0)
		throw PersonaException(Cadena("DNI ") + dni + " es invalido");
	
	this->dni = dni;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
int Persona::getDni()
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
const Cadena& Persona::getApellido()
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
const Cadena& Persona::getNombres()
{
	return this->nombres;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Persona::setFechaNac(const Fecha& fechaNac)
{
	if(fechaNac > Fecha::hoy())
		throw FechaException(Cadena("La fecha ") + fechaNac + " es mayor a hoy");
	
	this->fechaNac = fechaNac;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
const Fecha& Persona::getFechaNac()
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
char Persona::getSexo()
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
	Cadena linea;
	ent >> linea;
	
	vector<Cadena> campos;
	
	linea.split('|', campos);
	
	p.setDni(campos[0].aEntero());
	p.setApellido(campos[1]);
	p.setNombres(campos[2]);
	p.fechaNac(campos[3].aFecha());
	p.setSexo(campos[4][0]);
	
	return ent;
}
