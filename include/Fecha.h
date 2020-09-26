#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

///1/1/1601


class Fecha
{
private:
	int diaRel;
	
	static const int acumDias[2][13];
	
	static int diaDelAnio(int dia, int mes, int anio);
	static void diaYMes(int diaDelAnio, int anio, int& dia, int& mes);
	static bool esBisiesto(int anio);
	static bool esFechaValida(int dia, int mes, int anio);
	static int cantDiasMes(int mes, int anio);
	static int diasAniosCompletos(int aniosCompletos);
	
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	Fecha& operator +=(int dias);
	Fecha operator +(int dias) const;	///	Fecha sumarDias(int dias) const; // +
	void restarDias(int dias);
	Fecha restarDias(int dias) const;
	int operator -(const Fecha& f2) const;
	int difEnAnios(const Fecha& f2) const;
	int diaSemana() const;
	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);
	bool operator <(const Fecha& f2) const;
	bool operator >=(const Fecha& f2) const;
	
	friend Fecha operator +(int dias, const Fecha& f);
	friend istream& operator >>(istream& ent, Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);


#endif // FECHA_H
