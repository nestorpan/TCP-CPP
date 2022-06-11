#include <vector>
#include "Fecha.h"
#include "../Cadena/Cadena.h"

//                                      1   2   3   4    5    6    7    8    9   10   11   12   13
const int Fecha::acumDiasMes[14] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const int Fecha::acumDiasMesBis[14] = { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
const int Fecha::diasMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int Fecha::diasMesBis[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 1/9 -> 244
// 30/9 -> 273


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	setDMA(dia, mes, anio);
}

Fecha::Fecha(const Cadena& cadFecha) // 11/6/2022
{
	vector<Cadena> camposF = cadFecha.split('/');

	this->setDMA(camposF[0].toInt(), camposF[1].toInt(), camposF[2].toInt());
}

Fecha Fecha::operator +(int dias) const
{
	Fecha f;
	f.diaRel = this->diaRel + dias;
	return f;
}


int Fecha::operator -(const Fecha& otraFecha) const
{
	return this->diaRel - otraFecha.diaRel;
}


Fecha& Fecha::operator ++() //preincremento ++fecha
{
	++this->diaRel;
	return *this;
}


Fecha Fecha::operator ++(int) //postincremento fecha++
{
	Fecha f(*this);
	++this->diaRel;
	return f;
}


int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return (esBisiesto(anio)? acumDiasMesBis[mes] : acumDiasMes[mes]) + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}


void Fecha::setDMA(int dia, int mes, int anio)
{
	if(!esFechaValida(dia, mes, anio))
		throw FechaExc("La fecha no es válida");

	int cantAniosCompl = anio - ANIO_BASE;
	int diasAniosCompl = cantAniosCompl * 365 + cantAniosCompl / 4 - cantAniosCompl / 100 + cantAniosCompl / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);
}


void Fecha::getDMA(int& dia, int& mes, int& anio) const
{
	int cantAniosCompl = this->diaRel / 365;
	int diasAniosCompl = cantAniosCompl * 365 + cantAniosCompl / 4 - cantAniosCompl / 100 + cantAniosCompl / 400;

	while(diasAniosCompl >= this->diaRel)
	{
		cantAniosCompl--;
		diasAniosCompl = cantAniosCompl * 365 + cantAniosCompl / 4 - cantAniosCompl / 100 + cantAniosCompl / 400;
	}

	anio = ANIO_BASE + cantAniosCompl;

	int diaDelAnio = this->diaRel - diasAniosCompl;

	const int* acumDias = esBisiesto(anio) ? acumDiasMesBis : acumDiasMes;

	int i = 2;
	while(diaDelAnio > acumDias[i])
		i++;

	mes = i - 1;

	dia = diaDelAnio - acumDias[mes];
}


ostream& operator <<(ostream& sal, const Fecha& f)
{
	int dia, mes, anio;
	f.getDMA(dia, mes, anio);
	sal << dia << '/' << mes << '/' << anio;
	return sal;
}


istream& operator >>(istream& is, Fecha& f)
{
	int dia, mes, anio;
	char c;
	is >> dia >> c >> mes >> c >> anio;
	f.setDMA(dia, mes, anio);
	return is;
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	if(anio < ANIO_BASE)
		return false;

	if(mes < 1 || mes > 12)
		return false;

	if(dia < 1 || dia > (esBisiesto(anio)? diasMesBis[mes] : diasMes[mes]))
		return false;

	return true;
}

