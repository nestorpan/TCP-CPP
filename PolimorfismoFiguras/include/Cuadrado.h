#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"

class Cuadrado : public Figura
{
    private:
        double lado;

    public:
        Cuadrado(double lado);

        double perimetro() const;
        double area() const;
        double apotema() const;
};

#endif // CUADRADO_H
