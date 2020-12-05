#include "EmpleadoBuilder.h"

EmpleadoBuilder::EmpleadoBuilder()
:	PersonaBuilder(),
	legajo(1),
	fIngr(1, 1, 1800),
	sueldo(0)
{	
}

/*
Empleado EmpleadoBuilder::build()
{
	return Empleado(dni, apellido, nombre, sexo, fNac, legajo, fIngr, sueldo);
}
*/
