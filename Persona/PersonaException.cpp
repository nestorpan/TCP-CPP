#include "PersonaException.h"


PersonaException::PersonaException(const Cadena& mensaje)
: mensaje(mensaje)
{}


const Cadena& PersonaException::getMensaje() const
{
	return this->mensaje;
}
