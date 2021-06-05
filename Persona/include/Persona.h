#ifndef PERSONA_H
#define PERSONA_H

#include "../../Cadena/Cadena.h"
#include "../../Fecha/Fecha.h"


class Persona
{
private:
	unsigned dni;
	Cadena apyn;
	char sexo;
	Fecha fNac;
	char estadoCivil;

	Persona(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil);

public:
	Persona();

	void setDni(unsigned dni);
	unsigned getDni() const;

	void setApyn(const Cadena& apyn);
	const Cadena& getApyn() const;

	void setSexo(char sexo);
	char getSexo() const;

	void setFNac(const Fecha& fNac);
	const Fecha& getFNac() const;

	void setEstadoCivil(char estadoCivil);
	char getEstadoCivil() const;

	friend ostream& operator <<(ostream& sal, const Persona& p);

	friend class PersonaBuilder;

	///Persona& operator =(const Persona& otra);
};


#endif // PERSONA_H
