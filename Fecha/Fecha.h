#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include "FechaExc.h"

class Cadena;

#define ANIO_BASE 1601

using namespace std;


class Fecha
{
private:
	int diaRel;

	static const int acumDiasMes[14];
	static const int acumDiasMesBis[14];
	static const int diasMes[13];
	static const int diasMesBis[13];

	static int diaDelAnio(int dia, int mes, int anio);
	static bool esBisiesto(int anio);

public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	Fecha(const Cadena& cadFecha);

	static bool esFechaValida(int dia, int mes, int anio);

	Fecha operator +(int dias) const;
	int operator -(const Fecha& otraFecha) const; //const al final indica que no se modifica el objeto llamador
	Fecha& operator ++(); //preincremento ++fecha
	Fecha operator ++(int);	//postincremento fecha++
	void setDMA(int dia, int mes, int anio);
	void getDMA(int& dia, int& mes, int& anio) const;
	//TODO: Agregar métodos de comparación (< > <= >= == !=)
	//TODO: Agregar -- Pre y Post
	//TODO: Agregar += y -=
	//TODO: Agregar - dias
	//TODO: Investigar uso de cin
	//TODO: operator istream >>
};


ostream& operator <<(ostream& os, const Fecha& f);
istream& operator >>(istream& is, Fecha& f);


#endif // FECHA_H
