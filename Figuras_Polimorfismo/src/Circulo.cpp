#include "Circulo.h"


Circulo::Circulo(double radio)
: Figura("Circulo"), radio(radio)
{
	//ctor
}


double Circulo::perimetro() const
{
	return this->radio * 2 * PI;
}


double Circulo::area() const
{
	return this->radio * this->radio * PI;
}
