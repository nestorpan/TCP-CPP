#include <Fecha.h>
#include <FechaException.h>

#define ANIO_BASE 1601


Fecha::Fecha()
{
	this->diaRel = 1;
	//diaRel = 1;
}

/**

*/
Fecha::Fecha(int dia, int mes, int anio)
{
    if (!esFechaValida(dia, mes, anio)) {
        throw FechaException("La fecha no es valida");
    }

	int aniosCompletos = anio - ANIO_BASE; // ej con 2020 ==> 419

	int diasAniosCompletos =
        aniosCompletos * 365 +
        aniosCompletos / 4 -    // años bisiestos (le agrega un día c/4 años)
        aniosCompletos / 100 +  // cada 100 años se le agrega un día
        aniosCompletos / 400;   // cada 400 años se le agrega un día

    int diaDelAnioRel = diaDelAnio(dia, mes, anio);
	this->diaRel = diasAniosCompletos + diaDelAnioRel;
}


void Fecha::sumarDias(int dias)
{
	this->diaRel += dias;
}

Fecha Fecha::sumarDias(int dias) const
{
	Fecha fSuma(*this); // cta de copia

	fSuma.diaRel += dias;

	return fSuma;
}

bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return anio >= ANIO_BASE &&
           mes >= 1 && mes <= 12 &&
           dia >= 1 && dia <= cantDiasMes(mes, anio);
}

int Fecha::cantDiasMes(int mes, int anio)
{
	static const int vCantDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(mes == 2 && esBisiesto(anio))
		return 29;

	return vCantDias[mes];
}

int Fecha::diaDelAnio(int dia, int mes, int anio)
{
    static const int matAcumDias[2][12] =
    {/// E  F   M   A    M    J    J    A    S    O    N    D
        {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, ///Año no bisiesto
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335} ///Año bisiesto
    };
    ///Dia del año: 160 --> 160 - 151 = 9 => dia: 9, mes: 6
    ///Dia del año: 151 --> 151 - 120 = 31 => dia: 31, mes: 5


	return matAcumDias[esBisiesto(anio)? 1 : 0][mes-1] + dia;
}
