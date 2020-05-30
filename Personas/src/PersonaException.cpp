#include "PersonaException.h"


PersonaException::PersonaException(const Cadena& mensaje)
{
	this->mensaje = mensaje;
}


const Cadena& PersonaException::getMensaje() const
{
	return this->mensaje;
}
