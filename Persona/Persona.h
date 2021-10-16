#ifndef PERSONA_H
#define PERSONA_H

#include "../Cadena/Cadena.h"

class Persona
{
private:
	int dni;
	Cadena apellido;
	Cadena nombre;
	char sexo;
	Fecha fNac;

public:
	Persona();
	Persona(int dni = 0, const Cadena& apellido = Cadena(), const Cadena& nombre = Cadena(), char sexo = 'X', const Fecha& fNac = Fecha());

	int getDni() const { return this->dni; };
	const Cadena& getApellido() const { return this->apellido; };
	const Cadena& getNombre() const { return this->nombre; };
	char getSexo() const { return this->sexo; };
	const Fecha& getFNac() const { return this->fNac; };

	void setDni(int dni)/* { this->dni = dni; }*/;
	void setApellido(const Cadena& apellido);
	void setNombre(const Cadena& nombre);
	void setSexo(char sexo);
	void setFNac(const Fecha& fNac);

	int getEdad(const Fecha& fRef = Fecha::hoy()) const;
};


ostream& operator <<(ostream& sal, const Persona& p);
istream& operator >>(istream& ent, Persona& p);


#endif // PERSONA_H
