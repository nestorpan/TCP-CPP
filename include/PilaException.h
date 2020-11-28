#ifndef PILAEXCEPTION_H
#define PILAEXCEPTION_H

#include <string>

using namespace std;


class PilaException
{
private:
	string mensaje;
	
public:
	PilaException(const string& mensaje);
	
	const string& getMensaje();
};


#endif // PILAEXCEPTION_H
