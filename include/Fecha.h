#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

#define ANIO_BASE 1601


class Fecha
{
public:
	Fecha();
	Fecha(int d, int m, int a);
	
	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);
	Fecha operator +(int cantDias) const;
	Fecha& operator ++(); ///Pre
	Fecha operator ++(int); ///Pos
	
private:
	int diaDelAnio(int d, int m, int a);
	bool esBisiesto(int a) const;
	
	static const int mda[2][13];
	
	int diaRel;
	
///	friend Fecha operator +(int dias, const Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);

#endif // FECHA_H
