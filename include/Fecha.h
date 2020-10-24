#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <time.h>

using namespace std;

///1/1/1601

class Fecha
{
private:
	int diaRel;
    static bool esFechaValida(int d, int m, int a);
    static int diasAniosCompletos(int aniosCompletos);
	static void diaYMes(int diaDelAnio, int anio, int& dia, int& mes);
	static const int acumDias[2][13];

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	void sumarDias(int dias);
	Fecha sumarDias(int dias) const;

	Fecha& operator +=(int dias);
	Fecha operator +(int dias) const;	///	Fecha sumarDias(int dias) const; // +
    int operator -(const Fecha& f2) const;

	bool operator <(const Fecha& f2) const;
	bool operator >(const Fecha& f2) const;
	bool operator >=(const Fecha& f2) const;


	void restarDias(int dias);
	Fecha restarDias(int dias) const;
	int difEnDias(const Fecha* f2) const;
	int difEnAnios(const Fecha* f2) const;
	int diaSemana() const;

	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);

    static bool esBisiesto(int anio);
    static int cantDiasMes(int mes, int anio);

    int diaDelAnio(int dia, int mes, int anio);

    bool esMenor(const Fecha& f) const;
    bool esMayor(const Fecha& f) const;
    bool esIgual(const Fecha& f) const;

    static Fecha hoy();

    friend Fecha operator +(int dias, const Fecha& f);
    friend istream& operator >>(istream& ent, Fecha& f);

};

ostream& operator <<(ostream& sal, const Fecha& f);


#endif // FECHA_H
