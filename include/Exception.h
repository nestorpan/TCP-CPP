#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Cadena.h"


class Exception
{
private:
	Cadena mensaje;
	
public:
	Exception(const Cadena& mensaje);
	
	const Cadena& getMensaje();
};

#endif // EXCEPTION_H
