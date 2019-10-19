#ifndef PERSONAEXCEPTION_H
#define PERSONAEXCEPTION_H

#include "Exception.h"


class PersonaException : public Exception
{
public:
	PersonaException(const Cadena& mensaje);
};


#endif // PERSONAEXCEPTION_H
