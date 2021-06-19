#ifndef EMPLEADOBUILDER_H
#define EMPLEADOBUILDER_H

#include "PersonaBuilder.h"
#include "Empleado.h"


class EmpleadoBuilder : public PersonaBuilder
{
private:
	Fecha fIngr;
	double sueldo;
	
public:
	EmpleadoBuilder();
	
	void setfIngr(const Fecha& fIngr);
	void setSueldo(double sueldo);
	
	Empleado build();
};


#endif // EMPLEADOBUILDER_H
