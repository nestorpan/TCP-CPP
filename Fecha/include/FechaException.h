#ifndef FECHAEXCEPTION_H
#define FECHAEXCEPTION_H

#include <Cadena.h>


using namespace std;


class FechaException
{
	private:
		Cadena mensaje;
		
	public:
		FechaException(const Cadena& mensaje);
		
		const Cadena& getMensaje() const;
};


#endif // FECHAEXCEPTION_H
