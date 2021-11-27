#include <time.h>
#include "FechaInvalidaException.h"
#include "Fecha.h"


const int Fecha::acumDiasIniMes[2][14] =
{
//	   	 E	 F	 M	 A	 M    J    J    A    S    O    N    D
	//No bisiesto
	{ 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	//Bisiesto
	{ 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int d, int m, int a)
{
	this->setDMA(d, m, a);
}


Fecha Fecha::operator +(int dias) const
{
	if(this->diaRel + dias <= 0)
		throw FechaInvalidaException("La fecha es inválida");

	Fecha fechaSuma(*this);
	fechaSuma.diaRel += dias;
	return fechaSuma;
}


Fecha& Fecha::operator +=(int dias)
{
	if(this->diaRel + dias <= 0)
		throw FechaInvalidaException("La operación += no se pudo realizar: La suma de los días dejarían a la fecha inválida.");

	this->diaRel += dias;

	return *this;
}


int Fecha::operator -(const Fecha& f2) const
{
	return this->diaRel - f2.diaRel;
}


bool Fecha::esFechaValida(int d, int m, int a)
{
	return a >= ANIO_BASE && m >= 1 && m <= 12 && d >= 1 && d <= cantDiasMes(m, a);
}


int Fecha::cantDiasMes(int m, int a)
{
	static const int cdm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(m == 2 && esBisiesto(a))
		return 29;

	return cdm[m];
}


bool Fecha::esBisiesto(int a)
{
	return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}


int Fecha::diaDelAnio(int d, int m, int a)
{
	int fila = esBisiesto(a)? 1 : 0;

	return acumDiasIniMes[fila][m] + d;
}


void Fecha::getDMA(int& d, int& m, int& a) const
{
	int cantAnios = this->diaRel / 365;

	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;

	while(diasAniosCompl >= this->diaRel)
	{
		cantAnios--;
		diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	}

	a = ANIO_BASE + cantAnios;
	int diaDelAnio = this->diaRel - diasAniosCompl;

	int fila = esBisiesto(a)? 1 : 0;

	int mes = 2;
	while(diaDelAnio > acumDiasIniMes[fila][mes])
		mes++;

	mes--;

	m = mes;

	d = diaDelAnio - acumDiasIniMes[fila][mes];
}


void Fecha::setDMA(int d, int m, int a)
{
	if(!esFechaValida(d, m, a))
		throw FechaInvalidaException("La fecha es inválida");

	int cantAnios = a - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}

Fecha& Fecha::operator ++() /// Preincremento
{
	this->diaRel++;
	return *this;
}

Fecha Fecha::operator ++(int) /// Posincremento
{
	Fecha f(*this);
	this->diaRel++;
	return f;
}

Fecha operator +(int dias, const Fecha& f)
{
//	return f + dias;

	Fecha suma(f);
	suma.diaRel += dias;
	return suma;
}

bool Fecha::operator >(const Fecha& f2) const
{
	return this->diaRel > f2.diaRel;
}
bool Fecha::operator <(const Fecha& f2) const
{
	return this->diaRel < f2.diaRel;
}

bool Fecha::operator >=(const Fecha& f2) const
{
	return this->diaRel >= f2.diaRel;
}
bool Fecha::operator <=(const Fecha& f2) const
{
	return this->diaRel <= f2.diaRel;
}

int Fecha::difEnAnios(const Fecha& f2) const
{
	int d1, m1, a1, d2, m2, a2;

	this->getDMA(d1, m1, a1);
	f2.getDMA(d2, m2, a2);

	int dif = abs(a1 - a2);

	// fNac = 17/10/2000
	// hoy = 16/10/2021

	// m1 * 100 + d1 = 1000 + 17 = 1017
	// m2 * 100 + d2 = 1000 + 16 = 1016
	if(m1 * 100 + d1 > m2 * 100 + d2)
		dif--;

	return dif;
}

Fecha Fecha::hoy()
{
	time_t t = time(NULL);
	struct tm* tm = localtime(&t);
	return Fecha(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
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
