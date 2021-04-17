#ifndef FECHA_H
#define FECHA_H


class Fecha
{
private:
	unsigned long diaRel;
	
	static const int acumuladoMesesNoBisiesto[13];
	static const int acumuladoMesesBisiesto[13];
	
	static int diaDelAnio(int dia, int mes, int anio);
	static int esBisiesto(int anio);
	static void diaDelAnioADiaMes(int diaDelAnio, int anio, int* d, int* m);
	
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	Fecha sumarDias(int dias) const;
	
	void getDMA(int* d, int* m, int* a) const;
	
};


#endif // FECHA_H
