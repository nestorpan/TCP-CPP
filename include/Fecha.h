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
		
		Fecha(int diaRel);
		
	public:
		Fecha();
		
		///Constructor 
		Fecha(int dia, int mes, int anio); 
		
		void getDma(int& d, int& m, int& a);
		
		int diferencia(const Fecha f) const; /// operador -
		
		Fecha sumarDias(int dias) const;
		
		///Sumar dias no const
		void sumarDias(int dias);
		
		Fecha& operator +=(int dias);
		Fecha operator +(int dias) const;
		
		Fecha restarDias(int dias) const;
		
		int diaDelAnio() const;
		
		int diaDeLaSemana() const; ///Método
};


#endif // FECHA_H
