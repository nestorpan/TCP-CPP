#include "Rectangulo.h"


Rectangulo::Rectangulo(double lado1, double lado2)
: Figura("Rectangulo"), lado1(lado1), lado2(lado2)
{
	
}


double Rectangulo::perimetro() const
{
	return this->lado1 * 2 + this->lado2 * 2;
}


double Rectangulo::area() const
{
	return this->lado1 * this->lado2;
}
