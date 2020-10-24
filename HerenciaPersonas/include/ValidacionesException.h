#ifndef VALIDACIONESEXCEPTION_H
#define VALIDACIONESEXCEPTION_H

#include <Cadena.h>

class ValidacionesException
{
private:
	Cadena mensaje;

public:
	ValidacionesException(const Cadena& msj);

	const Cadena& getMensaje() const;
};

#endif // VALIDACIONESEXCEPTION_H
