#ifndef EXCEPTION_H
#define EXCEPTION_H


class Exception
{
private:
	Cadena mensaje;
	
public:
	Exception(const Cadena& mensaje);
	
	const Cadena& getMensaje() const;
};

#endif // EXCEPTION_H
