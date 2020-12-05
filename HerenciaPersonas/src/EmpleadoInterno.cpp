#include <EmpleadoInterno.h>


EmpleadoInterno::EmpleadoInterno()
{}


EmpleadoInterno::EmpleadoInterno
(
	unsigned dni,
	const Cadena& apellido,
	const Cadena& nombre,
	char sexo,
	const Fecha& fNac,
	unsigned legajo,
	const Fecha& fIngr,
	float sueldo
)
: Empleado(dni,	apellido, nombre, sexo, fNac, legajo, fIngr), sueldo(sueldo)
{
	//ctor
}


float EmpleadoInterno::getSueldo()
{
	return this->sueldo;
}


void EmpleadoInterno::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}


float EmpleadoInterno::calcularSueldo()
{
	return this->sueldo;
}


ostream& operator <<(ostream& sal, const EmpleadoInterno& emplInt)
{
	sal << (Empleado&)emplInt << '|' << emplInt.sueldo;
	return sal;
}


istream& operator >>(istream& ent, EmpleadoInterno& emplInt)
{
	ent >> (Empleado&)emplInt;
	ent.ignore(1);
	ent >> emplInt.sueldo;
	return ent;
}
