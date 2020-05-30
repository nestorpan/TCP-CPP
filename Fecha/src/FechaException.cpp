#include <FechaException.h>


FechaException::FechaException(const Cadena& mensaje)
{
	this->mensaje = mensaje;
}


const Cadena& FechaException::getMensaje() const
{
	return this->mensaje;
}
