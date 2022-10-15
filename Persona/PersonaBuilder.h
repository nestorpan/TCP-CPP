#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "Persona.h"


class PersonaBuilder
{
private:
	unsigned dni;
	Cadena apellido;
	Cadena nombre;
	Fecha fechaNacimiento;

public:
	PersonaBuilder();

	PersonaBuilder& setDni(unsigned dni) { this->dni = Persona::validarDni(dni); return *this; };
	PersonaBuilder& setApellido(const Cadena& apellido) { this->apellido = Persona::validarApellido(apellido); return *this; };
	PersonaBuilder& setNombre(const Cadena& nombre) { this->nombre = Persona::validarNombre(nombre); return *this; };
	PersonaBuilder& setFechaNacimiento(const Fecha& fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; return *this; };

	Persona buildEstatica();
	Persona* buildDinamica();
};


#endif // PERSONABUILDER_H
