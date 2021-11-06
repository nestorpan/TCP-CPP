#include <math.h>

#include "Recta.h"
#include "Triangulo.h"


Triangulo::Triangulo(const Cadena& nombre, const Punto& p1, const Punto& p2, const Punto& p3)
: Figura(nombre), p1(p1), p2(p2), p3(p3)
{}


double Triangulo::area() const
{
    double base = p1.distancia(p2);

    Recta rectaBase(p1, p2);
    double altura = rectaBase.distancia(p3);

    return (base * altura) / 2;
}


double Triangulo::perimetro() const
{
    double seg12 = p1.distancia(p2);
    double seg23 = p2.distancia(p3);
    double seg31 = p3.distancia(p1);

    return seg12 + seg23 + seg31;
}


double Triangulo::apotema() const
{
    double lado = p1.distancia(p2);

    return lado * sqrt(3) / 6;
}
