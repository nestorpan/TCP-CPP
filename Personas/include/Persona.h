#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;


class Persona
{
	private:
		int dni;
		Cadena apellido;
		Cadena nombres;
		Fecha fechaNac;
		char sexo;
		
	public:
		Persona(int dni = 0, const Cadena& apellido = "", const Cadena& nombres = "", const Fecha& fechaNac = Fecha(1, 1, 1601), char sexo = ' ');
		
		int getDni() const;
		void setDni(dni);
		
		const Cadena& getApellido();
		void setApellido(const Cadena& apellido);
		
		const Cadena& getNombre();
		void setNombres(const Cadena& nombres);
		
		const Fecha& getFechaNac() const;
		void setFechaNac(const Fecha& fechaNac);
		
		char getSexo() const;
		void setSexo(char sexo);
};


ostream& operator <<(ostream& sal, const Persona& p);
istream& operator >>(istream& ent, Persona& p);

#endif // PERSONA_H
