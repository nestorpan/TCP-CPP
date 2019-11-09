#ifndef FIGURA_H
#define FIGURA_H

#include "Cadena.h"

#define PI 3.14159265358979323846


class Figura
{
public:
	virtual Cadena nombre() const = 0;
	virtual double perimetro() const = 0;
	virtual double area() const = 0;
	virtual double apotema() const = 0;
};

#endif // FIGURA_H
