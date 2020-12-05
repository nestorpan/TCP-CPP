#include "ValidacionesException.h"
#include "Validaciones.h"


void Validaciones::mayorACero(unsigned u, const Cadena& mensaje)
{
	if(u == 0)
		throw ValidacionesException(mensaje);
}


void Validaciones::letrasYEspacios(const Cadena& cadena, const Cadena& mensaje)
{
	if(!cadena.letrasYEspacios())
		throw ValidacionesException(mensaje);
}


void Validaciones::sexo(char sexo, const Cadena& mensaje)
{
	if(sexo != 'M' && sexo != 'F')
		throw ValidacionesException(mensaje);
}


void Validaciones::fechaMayorIgual(const Fecha& fAValidar, const Fecha& desde, const Cadena& mensaje)
{
	if(fAValidar < desde)
		throw ValidacionesException(mensaje);
}


void Validaciones::fechaMenorIgual(const Fecha& fAValidar, const Fecha& hasta, const Cadena& mensaje)
{
	if(fAValidar > hasta)
		throw ValidacionesException(mensaje);
}
