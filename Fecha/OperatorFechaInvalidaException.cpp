#include <string.h>
#include "OperatorFechaInvalidaException.h"

OperatorFechaInvalidaException::OperatorFechaInvalidaException(const char* mensaje)
{
	strcpy(this->mensaje, mensaje);
}

const char* OperatorFechaInvalidaException::getMensaje() const
{
	return this->mensaje;
}

