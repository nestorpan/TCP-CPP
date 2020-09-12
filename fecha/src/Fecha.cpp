#include <FechaException.h>
#include <Fecha.h>

#define ANIO_BASE 1601


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	if(!esFechaValida(dia, mes, anio))
		throw FechaException("La fecha es invalida");
	
	int aniosCompletos = anio - ANIO_BASE;
	int diasAniosCompletos = aniosCompletos * 365 + aniosCompletos / 4 - aniosCompletos / 100 + aniosCompletos / 400;
	this->diaRel = diasAniosCompletos + diaDelAnio(dia, mes, anio);
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


int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	static const int acumDias[2][13] =
	{
		{0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
		{0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
	};
	
	return acumDias[esBisiesto(anio)? 1 : 0][mes] + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
    if(anio >= ANIO_BASE)
    {
        if(mes >= 1 && mes <= 12)
            if(dia >= 1 && dia <= cantDiasMes(mes, anio))
                return true;
	}
	
	return false;
}


int Fecha::cantDiasMes(int mes, int anio)
{
	static const int vCantDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(mes == 2 && esBisiesto(anio))
		return 29;
	
	return vCantDias[mes];
}
