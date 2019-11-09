#include "Cuadrado.h"


Cuadrado::Cuadrado(double lado)
{
	this->lado = lado;
}


string Cuadrado::nombre() const
{
	return "Cuadrado";
}


double Cuadrado::perimetro() const
{
	return lado * 4;
}


double Cuadrado::area() const
{
	return lado * lado;
}


double Cuadrado::apotema() const
{
	return lado / 2;
}
