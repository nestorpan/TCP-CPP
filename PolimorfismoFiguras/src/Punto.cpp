#include <math.h>
#include "Punto.h"


Punto::Punto(double x, double y)
: x(x), y(y)
{}


double Punto::operator -(const Punto& otro) const
{
	double catetoX = this->x - otro.x;
	double catetoY = this->y - otro.y;
	return sqrt(catetoX * catetoX + catetoY * catetoY);
}
