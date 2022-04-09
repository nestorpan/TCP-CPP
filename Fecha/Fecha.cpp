#include "Fecha.h"

// Constructores
Fecha::Fecha()
{
	this->diaRel = 1;// 01-01-1601
}

/**
    Calcular el d�a relativo en base a un d�a, mes y a�o
*/
Fecha::Fecha(int dia, int mes, int anio)
{
    // TODO implementar



    this->diaRel =      ;
}

// M�todos
Fecha Fecha::sumarDias(int dias) const
{
//	Fecha f; // instancia un objeto de tipo Fecha sin par�metros (cto por defecto ==> dialRel = 1)
//	f.diaRel = this->diaRel + dias;

//	return f;
    return *this + dias;
}

int Fecha::difEnDias(const Fecha* otraFecha) const
{
//	return this->diaRel - otraFecha->diaRel;
    return *this - otraFecha;
}


Fecha Fecha::operator +(int dias) const
{
	Fecha f;
	f.diaRel = this->diaRel + dias;
	return f;
}


int Fecha::operator -(const Fecha* otraFecha) const
{
	return this->diaRel - otraFecha->diaRel;
}

/*
int Fecha::getDiaRel() const
{
    return this->diaRel;
}
*/
