#include "ValidacionesException.h"


ValidacionesException::ValidacionesException(const Cadena& msj)
{
	this->mensaje = msj;
}


const Cadena& ValidacionesException::getMensaje() const
{
	return this->mensaje;
}
