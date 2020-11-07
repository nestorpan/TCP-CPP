#include "Pentagono.h"

Pentagono::Pentagono(double lado)
: Figura("Pentagono", 'M'), lado(lado)
{}


double Pentagono::perimetro() const
{
	return this->lado * 5;
}


double Pentagono::area() const
{
	return this->perimetro() * this->apotema() / 2;
}


double Pentagono::apotema() const
{
	return this->lado / 1.453085056;
}
