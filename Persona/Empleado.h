#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"


class Empleado : public Persona
{
private:
	long legajo;
	Cadena puesto;
	float sueldo;
	Fecha fIngr;

protected:
	Empleado(int dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac, long legajo, const Cadena& puesto, float sueldo, const Fecha& fIngr);
	
public:
	long getLegajo() const;
	void setLegajo(long legajo);
	const Cadena& getPuesto() const;
	void setPuesto(const Cadena& puesto);
	float getSueldo() const;
	void setSueldo(float sueldo);
	const Fecha& getFIngr() const;
	void setFIngr(const Fecha& fIngr);
	int getAntiguedad(const Fecha& fechaRef = Fecha::hoy()) const;
	
	friend istream& operator >>(istream& ent, Empleado& e);
	friend class EmpleadoBuilder;
};


ostream& operator <<(ostream& sal, const Empleado& e);


#endif // EMPLEADO_H
