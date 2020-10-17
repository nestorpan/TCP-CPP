#include "Validaciones.h"

unsigned Validaciones::mayorACero(unsigned u, const Cadena& mensaje)
{
	if(u == 0)
		throw ValidacionesException(mensaje);

	return u;
}


const Cadena& Validaciones::letrasYEspacios(const Cadena& cadena, const Cadena& mensaje)
{
	if(!cadena.letrasYEspacios())
		throw ValidacionesException(mensaje);

	return cadena;
}


char Validaciones::sexo(char sexo, const Cadena& mensaje)
{
    /*
	if (sexo != 'M' && sexo != 'F'?)
        throw ValidacionesException(mensaje)

    return sexo;
	*/

	return sexo != 'M' && sexo != 'F'? throw ValidacionesException(mensaje) : sexo;
}


const Fecha& Validaciones::fechaMayorIgual(const Fecha fAValidar, const Fecha& desde, const Cadena& mensaje)
{
	if(fAValidar < desde)
		throw ValidacionesException(mensaje);

	return fAValidar;
}


const Fecha& Validaciones::fechaMenorIgual(const Fecha fAValidar, const Fecha& hasta, const Cadena& mensaje)
{
	if(fAValidar > hasta)
		throw ValidacionesException(mensaje);

	return fAValidar;
}
