#include "FechaException.h"


FechaException::FechaException(const string& msj)
{
	this->mensaje = msj;
}


const string& FechaException::getMensaje() const
{
	return this->mensaje;
}
