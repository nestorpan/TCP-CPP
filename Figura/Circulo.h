#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"


class Circulo : public Figura
{
private:
    float radio;

    static const float PI;

public:
    Circulo(const string& nombre, float radio);
    ~Circulo();

    float area() const;
    float perimetro() const;
};


#endif // CIRCULO_H
