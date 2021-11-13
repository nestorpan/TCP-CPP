#include "Cuadrado.h"


Cuadrado::Cuadrado(const Cadena& nombre, double lado)
: Figura(nombre), lado(lado)
{}


double Cuadrado::area() const
{
    return lado * lado;
}


double Cuadrado::perimetro() const
{
    return lado * 4;
}


double Cuadrado::apotema() const
{
    return (double)lado / 2;
}
