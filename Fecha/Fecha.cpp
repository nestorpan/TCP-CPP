#include "Fecha.h"

Fecha::Fecha()
{
	this->diaRel = 1;
}

Fecha::Fecha(int d, int m, int a)
{
	/// cantA�os = a�oFecha - A�o base(1601)
	/// diasA�osCompl = cantA�os * 365 + cantA�os / 4 - cantA�os / 100 + cantA�os / 400
	/// diaRel = diasA�osCompl + diaDelA�oFecha
}

///Fecha Fecha::sumarDias(int dias) const;
void Fecha::sumarDias(int dias) {
    this->diaRel += dias;
}

/*
int Fecha::difDias(const Fecha* f2) const;
void Fecha::getDMA(int* d, int* m, int* a) const;
*/
