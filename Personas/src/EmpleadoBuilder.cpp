#include "EmpleadoBuilder.h"


EmpleadoBuilder::EmpleadoBuilder()
: fechaIngr(), fechaBaja(), sueldo(0)
{}


void EmpleadoBuilder::setFechaIngr(const Fecha& fechaIngr)
{
	this->fechaIngr = fechaIngr;
}


void EmpleadoBuilder::setFechaBaja(const Fecha& fechaBaja)
{
	this->fechaBaja = fechaBaja;
}


void EmpleadoBuilder::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}


Empleado EmpleadoBuilder::build()
{
	Empleado empleado(this->dni, this->apellido, this->nombres, this->fechaNac, this->sexo, this->fechaIngr, this->fechaBaja, this->sueldo);
	
	empleado.setDni(this->dni);
	
	return empleado;
}
