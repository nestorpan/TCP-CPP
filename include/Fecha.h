#ifndef FECHA_H
#define FECHA_H


class Fecha
{
	private:
		int diaRel; ///Atributo
		
		static const int matAcumDias[2][12];
		
		static bool esFechaValida(int dia, int mes, int anio);
		static int dmaADiaRel(int dia, int mes, int anio);
		static int diaDelAnio(int dia, int mes, int anio);
		static bool esBisiesto(int anio);
		
	public:
	///	Fecha();
		Fecha(int dia = 1, int mes = 1, int anio = 1601); ///Constructor
		
		int diferencia(const Fecha f) const;
		
		Fecha sumarDias(int dias) const; ///Elegir una versión
		void sumarDias(int dias);
		
		Fecha restarDias(int dias) const;
		
		int diaDelAnio() const;
		
		int diaDeLaSemana() const; ///Método
};


#endif // FECHA_H
