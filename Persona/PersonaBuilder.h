#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "Persona.h"


class PersonaBuilder
{
protected:
	unsigned dni;
	Cadena apyn;
	char sexo;
	Fecha fNac;
	char estadoCivil;
	
public:
	PersonaBuilder();
	
	void setDni(unsigned dni);
	void setApyn(const Cadena& apyn);
	void setSexo(char sexo);
	void setFNac(const Fecha& fNac);
	void setEstadoCivil(char estadoCivil);
	
	Persona build();
};


#endif // PERSONABUILDER_H
