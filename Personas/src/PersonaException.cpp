#include "PersonaException.h"


PersonaException::PersonaException(const string& mensaje)
{
	this->mensaje = mensaje;
}


const string& PersonaException::getMensaje() const
{
	return this->mensaje;
}
