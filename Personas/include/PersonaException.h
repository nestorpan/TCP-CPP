#ifndef PERSONAEXCEPTION_H
#define PERSONAEXCEPTION_H

#include <Cadena.h>


using namespace std;


class PersonaException
{
	private:
		Cadena mensaje;
		
	public:
		PersonaException(const Cadena& mensaje);
		
		const Cadena& getMensaje() const;
};


#endif // PERSONAEXCEPTION_H
