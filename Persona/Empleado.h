#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"


class Empleado : public Persona
{
private:
	Fecha fIngr;
	double sueldo;
	
	Empleado(unsigned dni, const Cadena& apyn, char sexo, const Fecha& fNac, char estadoCivil, const Fecha& fIngr, double sueldo);
	
public:
	Empleado();
		
	const Fecha& getFIngr();
	void setFIngr(const Fecha& fIngr);
	double getSueldo();
	void setSueldo(double sueldo);
	int getAntiguedad();
	
	void write(ofstream& stream) const;
	void read(ifstream& stream);
	
	friend ostream& operator <<(ostream& sal, const Empleado& empl);
	friend istream& operator >>(istream& ent, Empleado& empl);
	
	friend class EmpleadoBuilder;
};


#endif // EMPLEADO_H
