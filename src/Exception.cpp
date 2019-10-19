#include "Exception.h"


Exception::Exception(const Cadena& mensaje)
{
	this->mensaje = mensaje;
}


const Cadena& Exception::getMensaje() const
{
	return mensaje;
}
