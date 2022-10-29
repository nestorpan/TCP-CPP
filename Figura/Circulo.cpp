#include "Circulo.h"


Circulo::Circulo(double radio)
: radio(radio)
{}


double Circulo::area() const
{
	return PI * radio * radio;
}


double Circulo::perimetro() const
{
	return 2 * PI * radio;
}
