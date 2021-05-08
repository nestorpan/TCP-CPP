#ifndef FECHAEXCEPTION_H
#define FECHAEXCEPTION_H

#include <string>

using namespace std;


class FechaException
{
private:
	string mensaje;
	
public:
	FechaException(const string& msj);
	const string& getMensaje() const;
};


#endif // FECHAEXCEPTION_H
