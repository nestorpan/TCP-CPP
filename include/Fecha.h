#ifndef FECHA_H
#define FECHA_H

///1/1/1601

class Fecha
{
private:
	int diaRel;
    static bool esFechaValida(int d, int m, int a);

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	void sumarDias(int dias);
	Fecha sumarDias(int dias) const;
	void restarDias(int dias);
	Fecha restarDias(int dias) const;
	int difEnDias(const Fecha* f2) const;
	int difEnAnios(const Fecha* f2) const;
	int diaSemana() const;
	void getDMA(int* d, int* m, int* a) const;

    static bool esBisiesto(int anio);
    static int cantDiasMes(int mes, int anio);

    int diaDelAnio(int dia, int mes, int anio);


};


#endif // FECHA_H
