#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include "Cadena.h"
#include "Fecha.h"

using namespace std;


class Persona
{
private:
	int dni;
	Cadena apellido;
	Cadena nombres;
	char sexo;
	Fecha fechaNac;
	Cadena domicilio;
	Cadena nacionalidad;
	
public:
	Persona();
	Persona(int dni, const Cadena& apellido, const Cadena& nombres, char sexo, const Fecha& fechaNac, const Cadena& domicilio, const Cadena& nacionalidad);
	
	bool operator <(const Persona& otro) const;
	
	int getDni() const;
	void setDni(int dni);
	const Cadena& getApellido() const;
	void setApellido(const Cadena& apellido);
	const Cadena& getNombres() const;
	void setNombres(const Cadena& nombres);
	const Fecha& getFechaNac() const;
	void setFechaNac(const Fecha& fechaNac);
	const char getSexo() const;
	void setSexo(char sexo);
	const Cadena& getDomicilio() const;
	void setDomicilio(const Cadena& domicilio);
	const Cadena& getNacionalidad() const;
	void setNacionalidad(const Cadena& nacionalidad);
	
	static bool esMenorQuePorApellidoYNombres(const Persona& p1, const Persona& p2);
	
	friend ostream& operator <<(ostream& sal, const Persona& p);	
	friend istream& operator >>(istream& ent, Persona& p);
};


class PersonaBuilder
{
protected:
	int dni;
	Cadena apellido;
	Cadena nombres;
	char sexo;
	Fecha fechaNac;
	Cadena domicilio;
	Cadena nacionalidad;
	
public:
	PersonaBuilder();
	
	void setDni(int dni);
	void setApellido(const Cadena& apellido);
	void setNombres(const Cadena& nombres);
	void setFechaNac(const Fecha& fechaNac);
	void setSexo(char sexo);
	void setDomicilio(const Cadena& domicilio);
	void setNacionalidad(const Cadena& nacionalidad);
	
	Persona build() const;
};


#endif // PERSONA_H
