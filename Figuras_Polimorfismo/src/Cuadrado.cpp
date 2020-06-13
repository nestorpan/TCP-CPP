#include "Cuadrado.h"


Cuadrado::Cuadrado(double lado)
: Figura("Cuadrado"), lado(lado)
{
	
}


double Cuadrado::perimetro() const
{
	return this->lado * 4;
}


double Cuadrado::area() const
{
	return this->lado * this->lado;
}
