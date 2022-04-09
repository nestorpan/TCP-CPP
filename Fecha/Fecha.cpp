#include "Fecha.h"


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha f;
	f.diaRel = this->diaRel + dias;
	return f;
}


int Fecha::difEnDias(const Fecha* otraFecha) const
{
	return this->diaRel - otraFecha->diaRel;
}


Fecha Fecha::operator +(int dias) const
{
	Fecha f;
	f.diaRel = this->diaRel + dias;
	return f;
}


int Fecha::operator -(const Fecha* otraFecha) const
{
	return this->diaRel - otraFecha->diaRel;
}


