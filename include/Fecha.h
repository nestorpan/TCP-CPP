#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;


class Fecha
{
	public:
		Fecha();
		Fecha(int d, int m, int a);
		
		Fecha operator +(int dias) const;
		Fecha& operator ++(); ///Pre
		Fecha operator ++(int); ///Pos
		
		void getDMA(int& d, int& m, int& a) const;
		void setDMA(int d, int m, int a);
		
	private:
		static int vcdm[12];
		static int mda[2][13];
		
		Fecha(int diaRel);
		
		int diaRel;
		bool esFechaValida(int d, int m, int a) const;
		int cantDiasMes(int m, int a) const;
		bool esBisiesto(int a) const;
		int diaDelAnio(int d, int m, int a) const;
		
		friend Fecha operator +(int dias, const Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);

#endif // FECHA_H|
