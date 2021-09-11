#ifndef FECHAINVALIDAEXCEPTION_H
#define FECHAINVALIDAEXCEPTION_H


class FechaInvalidaException
{
private:
	char mensaje[200];

public:
	FechaInvalidaException(const char* mensaje);

	const char* getMensaje() const;
};


#endif // FECHAINVALIDAEXCEPTION_H
