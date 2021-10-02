#ifndef CADENAEXCEPTION_H
#define CADENAEXCEPTION_H

#include "Cadena.h"


class CadenaException
{
private:
	Cadena mensaje;
	
public:
	CadenaException(const Cadena& mensaje);
	const Cadena& getMensaje();
};

#endif // CADENAEXCEPTION_H
