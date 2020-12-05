#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <Cadena.h>
#include <Fecha.h>


class Validaciones
{
public:
	static void mayorACero(unsigned, const Cadena& mensaje);
	static void letrasYEspacios(const Cadena&, const Cadena& mensaje);
	static void sexo(char, const Cadena& mensaje);
//	static void fecha(const Fecha& fAValidar, const Fecha& desde, const Fecha& hasta, const Cadena& mensaje);
	static void fechaMayorIgual(const Fecha& fAValidar, const Fecha& desde, const Cadena& mensaje);
	static void fechaMenorIgual(const Fecha& fAValidar, const Fecha& hasta, const Cadena& mensaje);
	
};

#endif // VALIDACIONES_H
