#ifndef FIGURA_H
#define FIGURA_H

#include <Cadena.h>

class Figura
{
private:
	Cadena nombre;
	char genero;

public:
	Figura(const Cadena& nombre, char genero);

	virtual double perimetro() const = 0;

	virtual double area() const = 0;

	virtual double apotema() const = 0;

	char getGenero() const;
	Cadena getNombre() const;
};


#endif // FIGURA_H

