#ifndef EMPLEADOBUILDER_H
#define EMPLEADOBUILDER_H

#include <PersonaBuilder.h>
#include "Empleado.h"


class EmpleadoBuilder : public PersonaBuilder
{
private:
	unsigned legajo;
	Fecha fIngr;
	float sueldo;

public:
	EmpleadoBuilder();

	void setLegajo(unsigned val) { legajo = val; }
	void setFIngr(Fecha val) { fIngr = val; }
	void setSueldo(float val) { sueldo = val; }
//	Empleado build();
};

#endif // EMPLEADOBUILDER_H
