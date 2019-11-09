#include "Circulo.h"


Circulo::Circulo(double radio)
{
	this->radio = radio;
}


string Circulo::nombre() const
{
	return "Circulo";
}


double Circulo::perimetro() const
{
	return 2 * PI * radio;
}


double Circulo::area() const
{
	return PI * radio * radio;
}


double Circulo::apotema() const
{
	return radio;
}
