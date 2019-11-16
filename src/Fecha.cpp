#include <iostream>
#include "Fecha.h"

using namespace std;


const int Fecha::mda[2][13] =
{
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
};


Fecha::Fecha()
{
	diaRel = 1;
}


Fecha::Fecha(int d, int m, int a)
{
	setDMA(d, m, a);
}


void Fecha::getDMA(int& d, int& m, int& a) const
{
	int difAnios = diaRel / 365;
	int cantDiasAniosCompl = difAnios * 365 + difAnios / 4 - difAnios / 100 + difAnios / 400;
	
	while(cantDiasAniosCompl >= diaRel)
	{
		difAnios--;
		cantDiasAniosCompl = difAnios * 365 + difAnios / 4 - difAnios / 100 + difAnios / 400;
	}
	
	a = ANIO_BASE + difAnios;
	
	int diaDelAnio = diaRel - cantDiasAniosCompl;
	int fila = esBisiesto(a)? 1 : 0;
	m = 1;
	
	while(diaDelAnio > mda[fila][m])
		m++;
	
	d = diaDelAnio - mda[fila][m-1];
}


void Fecha::setDMA(int d, int m, int a)
{
	int difAnios = a - ANIO_BASE;
	diaRel = difAnios * 365 + difAnios / 4 - difAnios / 100 + difAnios / 400 + diaDelAnio(d, m, a);
}


Fecha Fecha::operator +(int cantDias) const
{
	Fecha suma(*this);
	
	suma.diaRel += cantDias;
	
	return suma;
}


Fecha& Fecha::operator ++() ///Pre
{
	diaRel++;
	return *this;
}


Fecha Fecha::operator ++(int) ///Pos
{
	Fecha antigua(*this);
	diaRel++;
	return antigua;
}


int Fecha::diaDelAnio(int d, int m, int a)
{
	return mda[esBisiesto(a)? 1 : 0][m - 1] + d;
}


bool Fecha::esBisiesto(int a) const
{
	return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}


ostream& operator <<(ostream& sal, const Fecha& f)
{
	int d, m, a;
	
	f.getDMA(d, m, a);
    
    sal << d << '/' << m << '/' << a;
	
	return sal;
}


istream& operator >>(istream& ent, Fecha& f)
{
	int d, m, a;
	char c;
	
	ent >> d >> c >> m >> c >> a;
	
	f.setDMA(d, m, a);
	
	return ent;
}
