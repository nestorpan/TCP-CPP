#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;


class Fecha
{
	private:
		int diaRel; ///Atributo
		
		static const int matAcumDias[2][12];
		
		static bool esFechaValida(int dia, int mes, int anio);
		static int dmaADiaRel(int dia, int mes, int anio);
		static int diaDelAnio(int dia, int mes, int anio);
		static bool esBisiesto(int anio);
		
		Fecha(int diaRel);
		
	public:
		Fecha();
		
		///Constructor 
		Fecha(int dia, int mes, int anio); 
		
		void getDma(int& d, int& m, int& a) const;
		
		int diferencia(const Fecha f) const; /// operador -
		
		Fecha sumarDias(int dias) const;
		
		///Sumar dias no const
		void sumarDias(int dias);
		
		Fecha& operator +=(int dias);
		Fecha operator +(int dias) const;
		int operator -(const Fecha& f2) const;
		bool operator <(const Fecha& f2) const;
		
		Fecha restarDias(int dias) const;
		
		int diaDelAnio() const;
		
		int diaDeLaSemana() const;
		
		friend Fecha operator +(int dias, const Fecha& f);
		friend istream& operator >>(istream& ent, Fecha& f);
};



ostream& operator <<(ostream& sal, const Fecha& f);


#endif // FECHA_H
