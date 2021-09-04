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
	if(!esFechaValida(d, m, a))
		return;

	int cantAnios = a - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}


Fecha Fecha::sumarDias(int dias) const
{

}


void Fecha::sumarDias(int dias)
{

}


int Fecha::difDias(const Fecha* f2) const
{

}


bool Fecha::esFechaValida(int d, int m, int a)
{
	return a >= ANIO_BASE &&
            m >= 1 && m <= 12 &&
                d >= 1 && d <= cantDiasMes(m, a);
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

/// dia del prog = 256
int Fecha::diaDelAnio(int d, int m, int a)
{
	int fila = esBisiesto(a)? 1 : 0;

	return acumDiasIniMes[fila][m] + d;
}


void Fecha::getDMA(int* d, int* m, int* a) const
{
	int cantAnios = this->diaRel / 365;

	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;

	while(diasAniosCompl >= this->diaRel)
	{
		cantAnios--;
		diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	}

	*a = ANIO_BASE + cantAnios;

	int diaDelAnio = this->diaRel - diasAniosCompl;

	int fila = esBisiesto(*a)? 1 : 0;

	int mes = 2;
	while(diaDelAnio > acumDiasIniMes[fila][mes])
		mes++;

	mes--;

	*m = mes;

	*d = diaDelAnio - acumDiasIniMes[fila][mes];
}


void Fecha::setDMA(int d, int m, int a)
{

}
