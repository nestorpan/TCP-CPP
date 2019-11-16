#ifndef PERSONA_H
#define PERSONA_H

#include "Cadena.h"
#include "Fecha.h"


class Persona
{
private:
	int dni;
	Cadena apellido;
	Cadena nombres;
	Fecha fechaNac;
	char sexo;
	Cadena domicilio;
	Cadena nacionalidad;
	
public:
	Persona();
	Persona(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo, const Cadena& domicilio, const Cadena& nacionalidad);
	
	bool operator <(const Persona& otra) const;
	
	int getDni() const;
	void setDni(int dni);
	const Cadena& getApellido() const;
	void setApellido(const Cadena& apellido);
	const Cadena& getNombres() const;
	void setNombres(const Cadena& nombres);
	const Fecha& getFechaNac() const;
	void setFechaNac(const Fecha& fechaNac);
	char getSexo() const;
	void setSexo(char sexo);
	const Cadena& getDomicilio() const;
	void setDomicilio(const Cadena& domicilio);
	const Cadena& getNacionalidad() const;
	void setNacionalidad(const Cadena& nacionalidad);
	
	static bool esMenorQuePorApellidoYNombres(const Persona& p1, const Persona& p2);
	
	friend ostream& operator <<(ostream& sal, const Persona& p);
	friend istream& operator >>(istream& ent, Persona& p);
};


/****** Builder ******/

class PersonaBuilder
{
protected:
	int dni;
	Cadena apellido;
	Cadena nombres;
	Fecha fechaNac;
	char sexo;
	Cadena domicilio;
	Cadena nacionalidad;

public:
	PersonaBuilder();
	
	void setDni(int dni);
	void setApellido(const Cadena& apellido);
	void setNombres(const Cadena& nombres);
	void setSexo(char sexo);
	void setFechaNac(const Fecha& fechaNac);
	void setDomicilio(const Cadena& domicilio);
	void setNacionalidad(const Cadena& nacionalidad);
	Persona build();
};


#endif // PERSONA_H
