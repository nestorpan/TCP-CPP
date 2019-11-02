#include <iostream>
#include "Fecha.h"

using namespace std;

int Fecha::vcdm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Fecha::mda[2][13] =
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


Fecha Fecha::operator +(int dias) const
{
	Fecha suma(*this);
	
	suma.diaRel += dias;
	
	return suma;
}


Fecha& Fecha::operator ++() ///Pre
{
	diaRel++;
	return *this;
}


Fecha Fecha::operator ++(int) ///Pos
{
	Fecha fechaAnt(*this);
	diaRel++;
	return fechaAnt;
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
	
	a = 1601 + difAnios;
	
	int diaDelAnio = diaRel - cantDiasAniosCompl;
	
	int fila = this->esBisiesto(a)? 1 : 0;
	
	m = 1;
	
	while(diaDelAnio > mda[fila][m])
		m++;
	
	d = diaDelAnio - mda[fila][m-1];
}


void Fecha::setDMA(int d, int m, int a)
{
	if(!esFechaValida(d, m, a))
		throw 1;
	
	int difAnios = a - 1601;
	
	diaRel = difAnios * 365 + difAnios / 4 - difAnios / 100 + difAnios / 400 + diaDelAnio(d, m, a);
}


bool Fecha::esFechaValida(int d, int m, int a) const
{
	return 	a > 1600 &&
			m >= 1 && m <= 12 &&
			d >= 1 && d <= cantDiasMes(m, a);
}


int Fecha::cantDiasMes(int m, int a) const
{
	if(m == 2 && esBisiesto(a))
		return 29;
	
	return vcdm[m-1];
}


bool Fecha::esBisiesto(int a) const
{
	return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}


int Fecha::diaDelAnio(int d, int m, int a) const
{
	return mda[esBisiesto(a)? 1 : 0][m - 1] + d;
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
