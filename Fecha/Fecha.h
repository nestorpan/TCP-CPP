#ifndef FECHA_H
#define FECHA_H

#include <iostream>

#define ANIO_BASE 1601


using namespace std;


class Fecha
{
private:
	int diaRel;
	
	static const int acumDiasIniMes[2][14];
	
	static bool esFechaValida(int d, int m, int a);
	static int diaDelAnio(int d, int m, int a);
	static int cantDiasMes(int m, int a);
	static bool esBisiesto(int a);
	
public:
	Fecha();
	Fecha(int d, int m, int a);
	~Fecha();
	
	Fecha operator +(int dias) const;
	Fecha operator -(int dias) const;
	Fecha& operator +=(int dias);
	Fecha& operator -=(int dias);
	int operator -(const Fecha& f2) const;
	Fecha& operator ++();	/// Preincremento
	Fecha operator ++(int);	/// Posincremento
	Fecha& operator --();	/// Preincremento
	Fecha operator --(int); /// Posdecremento
	bool operator <=(const Fecha& f2) const;
	bool operator >(const Fecha& f2) const;
	bool operator >=(const Fecha& f2) const;
	int diaSemana() const;
	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);
	int difEnAnios(const Fecha& f2) const;
	
	static Fecha hoy();
	
	friend Fecha operator +(int dias, const Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);

#endif // FECHA_H
