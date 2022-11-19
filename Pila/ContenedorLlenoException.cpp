#include "ContenedorLlenoException.h"

ContenedorLlenoException::ContenedorLlenoException(const Cadena& mensaje)
: mensaje(mensaje)
{}


const Cadena& ContenedorLlenoException::getMensaje() const
{
	return mensaje;
}
