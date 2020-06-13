#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "Persona.h"


class PersonaBuilder
{
	protected:
		int dni;
		Cadena apellido;
		Cadena nombres;
		Fecha fechaNac;
		char sexo;
		
	public:
		PersonaBuilder();
		
		void setDni(int dni);
		void setApellido(const Cadena& apellido);
		void setNombres(const Cadena& nombres);
		void setFechaNac(const Fecha& fechaNac);
		void setSexo(char sexo);
		Persona build();
};


#endif // PERSONABUILDER_H
