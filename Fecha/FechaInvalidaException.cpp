#include <string.h>

#include "FechaInvalidaException.h"


FechaInvalidaException::FechaInvalidaException(const char* mensaje)
{
	strcpy(this->mensaje, mensaje);
}


const char* FechaInvalidaException::getMensaje() const
{
	return this->mensaje;
}
