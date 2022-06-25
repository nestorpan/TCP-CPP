#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"


class Cuadrado : public Figura
{
private:
    float lado;

public:
    Cuadrado(const string& nombre, float lado);
    ~Cuadrado();

    float area() const;
    float perimetro() const;
};

#endif // CUADRADO_H
