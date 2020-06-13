#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

#include <Cadena.h>
#include <Fecha.h>


class PersonaBuilder;


using namespace std;


class Persona
{
	private:
		int dni;
		Cadena apellido;
		Cadena nombres;
		Fecha fechaNac;
		char sexo;
		
	protected:
		Persona(int dni = 0, const Cadena& apellido = "", const Cadena& nombres = "", const Fecha& fechaNac = Fecha(1, 1, 1601), char sexo = ' ');
		
	public:
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
		
		int getEdad(const Fecha& f);
		
		friend class PersonaBuilder;
};


ostream& operator <<(ostream& sal, const Persona& p);
istream& operator >>(istream& ent, Persona& p);

#endif // PERSONA_H
