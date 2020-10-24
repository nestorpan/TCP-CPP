#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include <Persona.h>


class PersonaBuilder
{
private:
	unsigned dni;
	Cadena apellido;
	Cadena nombre;
	char sexo;
	Fecha fNac;

public:
	PersonaBuilder();
	
	void setDni(unsigned dni);
	void setApellido(const Cadena& apellido);
	void setNombre(const Cadena& nombre);
	void setSexo(char sexo);
	void setFNac(const Fecha& fNac);
	
	Persona build();
};

#endif // PERSONABUILDER_H
