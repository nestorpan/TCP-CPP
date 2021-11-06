#include "Punto.h"
#include <math.h>


Punto::Punto()
{
    x = 0;
    y = 0;
}


Punto::Punto(double x, double y)
{
    this->x = x;
    this->y = y;
}


double Punto::getX() const
{
    return x;
}


double Punto::getY() const
{
    return y;
}


void Punto::setX(double x)
{
    this->x = x;
}


void Punto::setY(double y)
{
    this->y = y;
}


void Punto::setXY(double x, double y)
{
    this->x = x;
    this->y = y;
}


double Punto::distancia(const Punto& otroP) const
{
    return sqrt(pow(x - otroP.x, 2) + pow(y - otroP.y, 2));
}
