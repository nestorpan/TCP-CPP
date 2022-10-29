#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"


class Cuadrado : public Figura
{
private:
	double lado;

public:
	Cuadrado(double lado);

	double area() const override;
    double perimetro() const override;
};


#endif // CUADRADO_H
