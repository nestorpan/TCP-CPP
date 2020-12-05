#include <EmpleadoExterno.h>


EmpleadoExterno::EmpleadoExterno()
{}


float EmpleadoExterno::calcularSueldo()
{
	return this->importeHora * this->cantHorasTrabajadas;
}


ostream& operator <<(ostream& sal, const EmpleadoExterno& emplExt)
{
	sal << (Empleado&)emplExt << '|' << emplExt.importeHora << '|' << emplExt.cantHorasTrabajadas;
	return sal;
}


istream& operator >>(istream& ent, EmpleadoExterno& emplExt)
{
	ent >> (Empleado&)emplExt;
	ent.ignore(1);
	ent >> emplExt.importeHora;
	ent.ignore(1);
	ent >> emplExt.cantHorasTrabajadas;
	
	return ent;
}
