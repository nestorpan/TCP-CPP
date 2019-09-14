#ifndef FECHA_H
#define FECHA_H

#define ANIO_BASE 1601


class Fecha
{
	public:
		Fecha();
		Fecha(int d, int m, int a);
		
		void getDMA(int& d, int& m, int& a) const;
		Fecha operator +(int cantDias) const;
		
	private:
		int diaDelAnio(int d, int m, int a);
		bool esBisiesto(int a) const;
		
		static const int mda[2][13];
		
		int diaRel;
		
};

#endif // FECHA_H
