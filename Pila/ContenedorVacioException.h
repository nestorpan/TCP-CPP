#ifndef CONTENEDORLLENOEXCEPTION_H
#define CONTENEDORLLENOEXCEPTION_H

#include "../Cadena/Cadena.h"


class ContenedorLlenoException
{
private:
	Cadena mensaje;

public:
	ContenedorLlenoException(const Cadena& mensaje);

	const Cadena& getMensaje() const;
};


#endif // CONTENEDORLLENOEXCEPTION_H
