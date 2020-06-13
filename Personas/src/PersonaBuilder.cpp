#include "PersonaBuilder.h"
#include "PersonaException.h"


PersonaBuilder::PersonaBuilder()
: dni(0), apellido(), nombres(), fechaNac(), sexo(' ')
{
	
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void PersonaBuilder::setDni(int dni)
{
	if(dni < 0)
		throw PersonaException(Cadena("DNI ") + dni + " es invalido");
	
	this->dni = dni;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void PersonaBuilder::setApellido(const Cadena& apellido)
{
	this->apellido = apellido;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void PersonaBuilder::setNombres(const Cadena& nombres)
{
	this->nombres = nombres;
}


/** @brief (one liner)
  *
  * (documentation goes here)
  */
void PersonaBuilder::setFechaNac(const Fecha& fechaNac)
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
void PersonaBuilder::setSexo(char sexo)
{
	this->sexo = sexo;
}


Persona PersonaBuilder::build()
{
	return Persona(this->dni, this->apellido, this->nombres, this->fechaNac, this->sexo);
}
