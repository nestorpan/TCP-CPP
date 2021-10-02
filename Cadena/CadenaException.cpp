#include "CadenaException.h"


CadenaException::CadenaException(const Cadena& mensaje)
{
	this->mensaje = mensaje;
}


const Cadena& CadenaException::getMensaje()
{
	return this->mensaje;
}
