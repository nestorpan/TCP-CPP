#include <math.h>
#include "Pentagono.h"


Pentagono::Pentagono(double lado)
{
	this->lado = lado;
}


Cadena Pentagono::nombre() const
{
	return "Pentagono";
}


double Pentagono::perimetro() const
{
	return lado * 5;
}


double Pentagono::area() const
{
	return perimetro() * apotema() / 2;
}


double Pentagono::apotema() const
{
	double angulo = 2 * PI / 5;
	return lado / (2 * tan(angulo / 2));
}
