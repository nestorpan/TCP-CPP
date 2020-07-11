#include <iostream>
#include "Circulo.h"


Circulo::Circulo(double radio)
: Figura("Circulo"), radio(radio)
{
	//ctor
}


Circulo::~Circulo()
{
	cout << "Destruyendo el Circulo" << endl;
}


double Circulo::perimetro() const
{
	return this->radio * 2 * PI;
}


double Circulo::area() const
{
	return this->radio * this->radio * PI;
}
