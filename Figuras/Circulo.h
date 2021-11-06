#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

#define PI 3.14159265


class Circulo : public Figura
{
private:
    double radio;

public:
    Circulo(const Cadena& nombre, double radio);

    void setRadio(double radio);
    double getRadio() const;
    double area() const override;
    double perimetro() const override;
    double apotema() const;
};


#endif // CIRCULO_H
