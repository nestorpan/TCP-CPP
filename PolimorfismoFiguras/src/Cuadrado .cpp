#include "Cuadrado.h"

Cuadrado::Cuadrado(double lado)
: lado(lado)
{}

/*
double Cuadrado::perimetro()
{
	return lado * 4;
}
*/

double Cuadrado::area()
{
	return lado * lado;
}
