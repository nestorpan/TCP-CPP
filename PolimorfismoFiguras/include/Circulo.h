#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"
#include "Figura.h"


class Circulo : public Figura
{
private:
	Punto p;
	double radio;

public:
	Circulo(const Punto& p, double radio);

	double perimetro() const;
	double area() const;

	string getNombre() const;
};


#endif // CIRCULO_H
