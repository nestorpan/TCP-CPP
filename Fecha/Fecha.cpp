#include "Fecha.h"


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int d, int m, int a)
{
	/// cantAños = añoFecha - Año base(1601)
	/// diasAñosCompl = cantAños * 365 + cantAños / 4 - cantAños / 100 + cantAños / 400
	/// diaRel = diasAñosCompl + diaDelAñoFecha
}


Fecha Fecha::sumarDias(int dias) const;
void Fecha::sumarDias(int dias);
int Fecha::difDias(const Fecha* f2) const;
void Fecha::getDMA(int* d, int* m, int* a) const;
