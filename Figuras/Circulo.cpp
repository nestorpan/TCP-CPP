#include "Circulo.h"


Circulo::Circulo(const Cadena& nombre, double radio)
: Figura(nombre), radio(radio)
{}


double Circulo::area() const
{
    return PI * radio * radio;
}


double Circulo::perimetro() const
{
    return 2 * PI * radio;
}


double Circulo::apotema() const
{
    return radio;
}
