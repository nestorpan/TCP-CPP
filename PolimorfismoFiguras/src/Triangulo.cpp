#include <math.h>

#include "FiguraException.h"
#include "Triangulo.h"


Triangulo::Triangulo(const Punto& p1, const Punto& p2, const Punto& p3)
: p1(p1), p2(p2), p3(p3)
{
	if(
		p1.getX() * (p2.getY() - p3.getY()) +
		p2.getX() * (p3.getY() - p1.getY()) +
		p3.getX() * (p1.getY() - p2.getY())
		== 0
	)
		throw FiguraException("Triangulo(): Los puntos son colineares, no pueden formar un triángulo.");
}


double Triangulo::perimetro() const
{
	return (p1 - p2) + (p2 - p3) + (p3 - p1);
}


double Triangulo::area() const
{
	return fabs(
		p1.getX() * (p2.getY() - p3.getY()) +
		p2.getX() * (p3.getY() - p1.getY()) +
		p3.getX() * (p1.getY() - p2.getY())
		) / 2;
}

string Triangulo::getNombre() const {
    return "Triángulo";
};
