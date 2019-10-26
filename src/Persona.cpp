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


const Cadena& Persona::getApellido() const 
{ 
	return apellido; 
} 
 
 
void Persona::setApellido(const Cadena& apellido) 
{ 
	this->apellido = apellido; 
} 
 
 
const Cadena& Persona::getNombres() const 
{ 
	return nombres; 
} 
 
 
void Persona::setNombres(const Cadena& nombres) 
{ 
	this->nombres = nombres; 
} 
 
 
const Fecha& Persona::getFechaNac() const 
{ 
	return fechaNac; 
} 
 
 
void Persona::setFechaNac(const Fecha& fechaNac) 
{ 
	this->fechaNac = fechaNac; 
} 
 
 
const char Persona::getSexo() const 
{ 
	return sexo; 
} 


void Persona::setSexo(char sexo) 
{ 
	this->sexo = sexo; 
} 


const Cadena& Persona::getDomicilio() const 
{ 
	return domicilio; 
} 


void Persona::setDomicilio(const Cadena& domicilio) 
{ 
	this->domicilio = domicilio; 
} 
 
 
const Cadena& Persona::getNacionalidad() const 
{ 
	return nacionalidad; 
} 
 
 
void Persona::setNacionalidad(const Cadena& nacionalidad) 
{ 
	this->nacionalidad = nacionalidad; 
} 


/****** Builder ******/

PersonaBuilder::PersonaBuilder() 
:dni(0), sexo('M'), fechaNac(1, 1, 1900) 
{ 
///	fechaNac = Fecha(1, 1, 1900); 
}


void PersonaBuilder::setDni(int dni) 
{ 
	this->dni = dni; 
} 


void PersonaBuilder::setApellido(const Cadena& apellido) 
{ 
	this->apellido = apellido; 
}


void PersonaBuilder::setNombres(const Cadena& nombres) 
{ 
	this->nombres = nombres; 
} 


void PersonaBuilder::setFechaNac(const Fecha& fechaNac) 
{ 
	this->fechaNac = fechaNac; 
} 


void PersonaBuilder::setSexo(char sexo) 
{ 
	this->sexo = sexo; 
}


void PersonaBuilder::setDomicilio(const Cadena& domicilio) 
{ 
	this->domicilio = domicilio; 
} 


void PersonaBuilder::setNacionalidad(const Cadena& nacionalidad) 
{ 
	this->nacionalidad = nacionalidad; 
}


Persona PersonaBuilder::build()
{
	return Persona(dni, apellido, nombres, fechaNac, sexo, domicilio, nacionalidad);
}
