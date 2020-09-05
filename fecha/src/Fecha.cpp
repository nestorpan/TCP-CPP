#include <Fecha.h>


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	
}


void Fecha::sumarDias(int dias)
{
	this->diaRel += dias;
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha fSuma(*this);
	
	fSuma.diaRel += dias;
	
	return fSuma;
}
