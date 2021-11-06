#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"


class Cuadrado : public Figura
{
private:
    int lado;

public:
    Cuadrado(const Cadena& nombre, double lado);
    
    void setLado(double lado);
    
    double area() const;
    double perimetro() const;
    double apotema() const;
};


#endif // CUADRADO_H