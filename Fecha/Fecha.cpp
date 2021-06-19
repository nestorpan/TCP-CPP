#include "Fecha.h"
#include "FechaException.h"
#include "time.h"
#include <iomanip>
#include <fstream>


#define ANIO_BASE 1601

const int Fecha::acumuladoMesesNoBisiesto[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int Fecha::acumuladoMesesBisiesto[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	this->setDMA(dia, mes, anio);
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha fSuma(*this);
	fSuma.diaRel += dias;
	return fSuma;
}


void Fecha::getDMA(int& d, int& m, int& a) const
{
	int cantAniosComplCalc = this->diaRel / 365;
	unsigned long diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

	while(diasAniosComplCalc >= this->diaRel)
	{
		cantAniosComplCalc--;
		diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
	}

	int anio = ANIO_BASE + cantAniosComplCalc;

	a = anio;

	int diaDelAnio = this->diaRel - diasAniosComplCalc;

	diaDelAnioADiaMes(diaDelAnio, anio, d, m);
}


void Fecha::setDMA(int d, int m, int a)
{
   if(!esFechaValida(d, m, a))
		throw FechaException("La fecha es inválida");

	int cantAnios = a - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}

	
Fecha Fecha::operator +(int dias) const
{
	return sumarDias(dias);
}


Fecha& Fecha::operator +=(int dias)
{
	this->diaRel += dias;

	return *this;
}


Fecha& Fecha::operator ++()	/// Pre
{
	++this->diaRel;
	return *this;
}


Fecha Fecha::operator ++(int) /// Pos
{
	Fecha temp(*this);
	this->diaRel++;
	return temp;
}


Fecha& Fecha::operator --()	/// Pre
{
	--this->diaRel;
	return *this;
}


Fecha Fecha::hoy()
{
	time_t segs = time(NULL);

	struct tm* timeMachine = localtime(&segs);

	int dia = timeMachine->tm_mday;
	int mes = timeMachine->tm_mon + 1;
	int anio = timeMachine->tm_year + 1900;

	return Fecha(dia, mes, anio);
}


Fecha operator +(int dias, const Fecha& f)
{
	Fecha fSuma(f);

	fSuma.diaRel += dias;

	return fSuma;
}

/********** Funciones miembro (métodos) privadas **********/

int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return (esBisiesto(anio)? acumuladoMesesBisiesto[mes] : acumuladoMesesNoBisiesto[mes]) + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int& d, int& m)
{
	const int* acumuladoMeses = esBisiesto(anio)? acumuladoMesesBisiesto : acumuladoMesesNoBisiesto;

	int mes = 2;

	while(mes <= 12 && diaDelAnio > acumuladoMeses[mes])
		mes++;

	mes--;
	m = mes;
	
	d = diaDelAnio - acumuladoMeses[mes];
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return anio >= ANIO_BASE && mes >= 1 && mes <= 12 && dia >= 1 && dia <= cantDiasMes(mes, anio);
}


int Fecha::cantDiasMes(int mes, int anio)
{
	static const int vCantDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(mes == 2 && esBisiesto(anio))
		return 29;

	return vCantDias[mes];
}


Fecha Fecha::sumarMeses(int cantmeses)const
{
    Fecha fsuma(*this);
    int dia,mes,anio;
    this->getDMA(dia, mes, anio);
	
    if(esBisiesto(anio))
    {
        fsuma.diaRel-=acumuladoMesesBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesBisiesto[mes+1+cantmeses];
    }
    else
    {
        fsuma.diaRel-=acumuladoMesesNoBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesNoBisiesto[mes+1+cantmeses];
    }
    return(fsuma);
}


int Fecha::difEnAnios(const Fecha& f2) const
{
	int d1, m1, a1, d2, m2, a2;
	
	this->getDMA(d1, m1, a1);
	f2.getDMA(d2, m2, a2);
	
	int dif = a2 - a1;
	
	if(m2 * 100 + d2 < m1 * 100 + d1)
		dif--;
	
	return dif;
}


void Fecha::write(ofstream& stream) const
{
	stream.write((char*)&this->diaRel, sizeof(unsigned long));
}


void Fecha::read(ifstream& stream)
{
	stream.read((char*)&this->diaRel, sizeof(unsigned long));
}


ostream& operator <<(ostream& sal, const Fecha& f)
{
	int dia, mes, anio;
	f.getDMA(dia, mes, anio);
	
	return sal << setfill('0') << setw(2) << dia << '/' << setfill('0') << setw(2) << mes << '/' << setfill('0') << setw(4) << anio;
}


istream& operator >>(istream& ent, Fecha& f)
{
	int d, m, a;
	char c;
	
	ent >> d >> c >> m >> c >> a;
	f.setDMA(d, m, a);
	
	return ent;
}

