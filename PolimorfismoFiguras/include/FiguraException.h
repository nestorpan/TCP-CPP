#ifndef FIGURAEXCEPTION_H
#define FIGURAEXCEPTION_H

#include <string>

using namespace std;


class FiguraException
{
private:
	string mensaje;

public:
	FiguraException(const string& mensaje);

	const string& getMensaje() { return mensaje; };
};


#endif // FIGURAEXCEPTION_H
