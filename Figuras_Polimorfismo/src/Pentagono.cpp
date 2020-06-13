#include "Pentagono.h"


Pentagono::Pentagono(double lado)
: Figura("Pentagono"), lado(lado)
{
	//ctor
}


double Pentagono::perimetro() const
{
	return this->lado * 5;
}


double Pentagono::area() const
{
	return 1.72 * this->lado * this->lado;
}
