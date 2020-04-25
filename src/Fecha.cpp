#include <iostream>
#include "Fecha.h"
#include "FechaException.h"

using namespace std;


const int Fecha::matAcumDias[2][12] =
{/// E  F   M   A    M    J    J    A    S    O    N    D
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, ///Año no bisiesto
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335} ///Año bisiesto
};
///Dia del año: 160 --> 160 - 151 = 9 => dia: 9, mes: 6
///Dia del año: 151 --> 151 - 120 = 31 => dia: 31, mes: 5


Fecha::Fecha(int diaRel)
{
	this->diaRel = diaRel;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	///TODO: pasar dma a diaRel.
	
	if(!esFechaValida(dia, mes, anio))
	{	///TODO: Lanzar una excepción
		throw FechaException("La fecha es invalida");
	}
	
	this->diaRel = dmaADiaRel(dia, mes, anio);
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return false;
}


int Fecha::dmaADiaRel(int dia, int mes, int anio)
{
	int cantAnios = anio - 1601;
	int diaRelativo = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400 + diaDelAnio(dia, mes, anio);
	return diaRelativo;
}


void Fecha::getDma(int& dia, int& mes, int& anio)
{
	int cantAnios = this->diaRel / 365;
	
	int diaRelCalc = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	
	while(diaRelCalc >= this->diaRel)
	{
		cantAnios--;
		diaRelCalc = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	}
	
	anio = 1601 + cantAnios;
	
	int diaDelAnio = this->diaRel - diaRelCalc;
	
	int filaAcum = esBisiesto(anio)? 1 : 0;
	
	mes = 0;
	
	while(diaDelAnio > matAcumDias[filaAcum][mes])
	{
		mes++;
	}
	
	dia = diaDelAnio - matAcumDias[filaAcum][mes-1];
}


int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return matAcumDias[esBisiesto(anio)? 1 : 0][mes-1] + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha suma(this->diaRel + dias);
	return suma;
}


void Fecha::sumarDias(int dias)
{
	this->diaRel += dias;
}


Fecha& Fecha::operator +=(int dias)
{
	this->diaRel += dias;
	return *this;
}


Fecha Fecha::operator +(int dias) const
{
	Fecha suma(this->diaRel + dias);
	return suma;
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
