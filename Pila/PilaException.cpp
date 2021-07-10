#include "PilaException.h"


PilaException::PilaException(const string& mensaje)
: mensaje(mensaje)
{}


const string& PilaException::getMensaje() const
{
	return this->mensaje;
}
