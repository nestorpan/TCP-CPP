#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include "Punto.h"


class Triangulo : public Figura
{
private:
    Punto p1;
    Punto p2;
    Punto p3;

public:
    Triangulo(const Cadena& nombre, const Punto& p1, const Punto& p2, const Punto& p3);

    double area() const override;
    double perimetro() const override;
    double apotema() const override;
};


#endif // TRIANGULO_H
