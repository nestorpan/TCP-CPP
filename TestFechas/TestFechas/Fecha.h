#ifndef FECHA_H
#define FECHA_H


class Fecha
{
private:
	unsigned long diaRel;
	
public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	
	Fecha sumarDias(int dias) const;
};


#endif // FECHA_H
