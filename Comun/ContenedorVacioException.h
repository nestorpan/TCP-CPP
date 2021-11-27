#ifndef CONTENEDORVACIOEXCEPTION_H
#define CONTENEDORVACIOEXCEPTION_H

#include <string>

#include "Exception.h"


class ContenedorVacioException : public Exception
{
public:
	ContenedorVacioException(const string& mensaje = "Contenedor vacio.");
};


#endif // CONTENEDORVACIOEXCEPTION_H
