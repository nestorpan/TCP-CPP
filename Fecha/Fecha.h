#ifndef FECHA_H
#define FECHA_H

#define ANIO_BASE 1601


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
	
	Fecha operator +(int dias) const;
	Fecha operator -(int dias) const;
	Fecha& operator +=(int dias);
	Fecha& operator -=(int dias);
	int operator -(const Fecha& f2) const;
	Fecha operator ++();
	int diaSemana() const;
	void getDMA(int& d, int& m, int& a) const;
	void setDMA(int d, int m, int a);
};


#endif // FECHA_H
