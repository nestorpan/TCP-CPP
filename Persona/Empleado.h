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

public:
	Empleado(int dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac, long legajo, const Cadena& puesto, float sueldo, const Fecha& fIngr);
	
	long getLegajo();
	void setLegajo(long legajo);
	const Cadena& getPuesto();
	void setPuesto(const Cadena& puesto);
	float getSueldo();
	void setSueldo(float sueldo);
	const Fecha& getFIngr();
	void setFIngr(const Fecha& fIngr);
};


#endif // EMPLEADO_H
