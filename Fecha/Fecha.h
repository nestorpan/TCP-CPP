#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;


class Fecha
{
private:
	unsigned long diaRel;
	
	static const int acumuladoMesesNoBisiesto[13];
	static const int acumuladoMesesBisiesto[13];
	
	static int diaDelAnio(int dia, int mes, int anio);
	static bool esBisiesto(int anio);
	static void diaDelAnioADiaMes(int diaDelAnio, int anio, int& d, int& m);
	
	static bool esFechaValida(int dia, int mes, int anio);
	static int cantDiasMes(int mes, int anio);
	
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	Fecha sumarDias(int dias) const;
	Fecha sumarMeses(int cantmeses) const;
	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);
	
	Fecha operator +(int dias) const;
	Fecha& operator +=(int dias);
	Fecha& operator ++(); /// Pre
	Fecha operator ++(int); /// Pos
	Fecha& operator --();	/// Pre
	
	static Fecha hoy();
	int difEnAnios(const Fecha& f2) const;
	
	friend Fecha operator +(int dias, const Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);


#endif // FECHA_H
