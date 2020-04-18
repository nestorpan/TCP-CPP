#include <iostream>
#include "Fecha.h"

using namespace std;


const int Fecha::matAcumDias[2][12] =
{/// E  F   M   A    M    J    J    A    S    O    N    D
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, ///Año no bisiesto
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335} ///Año bisiesto
};


Fecha::Fecha(int dia, int mes, int anio)
{
	///TODO: pasar dma a diaRel.
	
	if(!esFechaValida(dia, mes, anio))
	{	///TODO: Lanzar una excepción
		throw -1;
	}
	
	this->diaRel = dmaADiaRel(dia, mes, anio);
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return true;
}


int Fecha::dmaADiaRel(int dia, int mes, int anio)
{
	int cantAnios = anio - 1601;
	int diaRelativo = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400 + diaDelAnio(dia, mes, anio);
	return diaRelativo;
}


int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return matAcumDias[esBisiesto(anio)? 1 : 0][mes-1] + dia;
}


bool Fecha::esBisiesto(int anio)
{
//	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

/*
int Fecha::diaDeLaSemana()
{
	return 0;
}


int Fecha::diferencia(Fecha f)
{
	return this->diaRel - f.diaRel;
}
*/
