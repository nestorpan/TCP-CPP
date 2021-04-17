#include "Fecha.h"

#define ANIO_BASE 1601

const int Fecha::acumuladoMesesNoBisiesto[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int Fecha::acumuladoMesesBisiesto[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	int cantAnios = anio - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha fSuma(*this);
	fSuma.diaRel += dias;
	return fSuma;
}


void Fecha::getDMA(int* d, int* m, int* a) const
{
	int cantAniosComplCalc = this->diaRel / 365;
	unsigned long diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
	
	while(diasAniosComplCalc >= this->diaRel)
	{
		cantAniosComplCalc--;
		diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
	}
	
	int anio = ANIO_BASE + cantAniosComplCalc;
	
	*a = anio;
	
	int diaDelAnio = this->diaRel - diasAniosComplCalc;
	
	diaDelAnioADiaMes(diaDelAnio, anio, d, m);
}


/********** Funciones miembro (métodos) privadas **********/

int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return (esBisiesto(anio)? acumuladoMesesBisiesto[mes] : acumuladoMesesNoBisiesto[mes]) + dia;
}


int Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int* d, int* m)
{
	const int* acumuladoMeses = esBisiesto(anio)? acumuladoMesesBisiesto : acumuladoMesesNoBisiesto;
	
	int mes = 2;
	
	while(mes <= 12 && diaDelAnio > acumuladoMeses[mes])
		mes++;
	
	mes--;
	*m = mes;
	
	*d = diaDelAnio - acumuladoMeses[mes];
}
