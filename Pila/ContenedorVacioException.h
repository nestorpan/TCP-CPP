#ifndef CONTENEDORVACIOEXCEPTION_H
#define CONTENEDORVACIOEXCEPTION_H

#include "../Cadena/Cadena.h"


class ContenedorVacioException
{
private:
	Cadena mensaje;

public:
	ContenedorVacioException(const Cadena& mensaje);

	const Cadena& getMensaje() const;
};


#endif // CONTENEDORVACIOEXCEPTION_H
