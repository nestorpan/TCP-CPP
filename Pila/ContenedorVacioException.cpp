#include "ContenedorVacioException.h"


ContenedorVacioException::ContenedorVacioException(const Cadena& mensaje)
: mensaje(mensaje)
{}


const Cadena& ContenedorVacioException::getMensaje() const
{
	return mensaje;
}
