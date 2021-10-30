#include "EmpleadoBuilder.h"


EmpleadoBuilder::EmpleadoBuilder()
: PersonaBuilder(), legajo(0), sueldo(0), fIngr(Fecha::hoy())
{}


void EmpleadoBuilder::setLegajo(long legajo) {
	this->legajo = legajo;
}


void EmpleadoBuilder::setPuesto(Cadena puesto) {
	this->puesto = puesto;
}


void EmpleadoBuilder::setSueldo(float sueldo) {
	this->sueldo = sueldo;
}


void EmpleadoBuilder::setFIngr(Fecha fIngr) {
	this->fIngr = fIngr;
}


Empleado EmpleadoBuilder::build() const
{
    return Empleado(dni, apellido, nombre, sexo, fNac,
                    legajo, puesto, sueldo, fIngr);
}


Empleado* EmpleadoBuilder::buildDin() const
{
    return new Empleado(dni, apellido, nombre, sexo, fNac, legajo, puesto, sueldo, fIngr);
}
