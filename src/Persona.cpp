#include "Persona.h"

Persona::Persona()
{
	
}


Persona::Persona(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo, const Cadena& domicilio, const Cadena& nacionalidad)
{
	if(dni < 0)
		throw PersonaException("El DNI es invalido");
	
	this->dni = dni;

}

int Persona::getDni() const
{
	return dni;
}


void Persona::setDni(int dni)
{
	if(dni < 0)
		throw PersonaException("El DNI es invalido");
	
	this->dni = dni;
}


const Cadena& Persona::getApellido() const;
void Persona::setApellido(const Cadena& apellido);
const Cadena& Persona::getNombres() const;
void Persona::setNombres(const Cadena& nombres);
const Fecha& Persona::getFechaNac() const;
void Persona::setFechaNac(const Fecha& fechaNac);
char Persona::getSexo() const;
void Persona::setSexo(char sexo);
const Cadena& Persona::getDomicilio() const;
void Persona::setDomicilio(const Cadena& domicilio);
const Cadena& Persona::getNacionalidad();
void Persona::setNacionalidad(const Cadena& nacionalidad);


/****** Builder ******/

PersonaBuilder();

void setDni(int dni);
void setApellido(const Cadena& apellido);
void setNombres(const Cadena& nombres);
void setFechaNac(const Fecha& fechaNac);
void setSexo(char sexo);
void setDomicilio(const Cadena& domicilio);
void setNacionalidad(const Cadena& nacionalidad);


Persona PersonaBuilder::build()
{
	return Persona(dni, apellido, nombres, fechaNac, sexo, domicilio, nacionalidad);
}
