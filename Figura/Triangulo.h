#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"


class Triangulo : public Figura
{
private:
    float base;
    float altura;
    float lado1;
    float lado2;
    float lado3;

public:
    Triangulo(const string& nombre, float base, float altura, float lado1, float lado2, float lado3);
    ~Triangulo();

    float area() const;
    float perimetro() const;
};


#endif // TRIANGULO_H
