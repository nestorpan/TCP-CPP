#include "Circulo.h"

Circulo::Circulo(double radio)
: Figura("Circulo", 'M'), radio(radio)
{}


double Circulo::perimetro() const
{
	return 2 * PI * this->radio;
}


double Circulo::area() const
{
	return PI * this->radio * this->radio;
}


double Circulo::apotema() const
{
	return this->radio;
}
