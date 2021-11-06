#include <math.h>
#include "Recta.h"


Recta::Recta()
{}


Recta::Recta(const Punto& p1, const Punto& p2)
{
    this->p1 = p1;
    this->p2 = p2;
}


double Recta::distancia(const Punto& p) const
{
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();

    double x0 = p.getX();
    double y0 = p.getY();

    double rY2Y1 = y2 - y1;
    double rX2X1 = x2 - x1;


    double a = rY2Y1 * x0;
    double b = rX2X1 * y0;
    double c = x2 * y1;
    double d = y2 * x1;

    return abs(a - b + c - d) / sqrt(rY2Y1 * rY2Y1 + rX2X1 * rX2X1);
}
