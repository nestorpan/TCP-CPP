#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;


class Exception
{
private:
	string mensaje;

public:
	Exception(const string& mensaje);

	const string& getMensaje() const;
};

#endif // EXCEPTION_H
