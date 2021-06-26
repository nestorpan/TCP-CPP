#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Punto.h"
#include "Figura.h"
#include <string>


class Triangulo : public Figura
{
private:
	Punto p1;
	Punto p2;
	Punto p3;

public:
	Triangulo(const Punto& p1, const Punto& p2, const Punto& p3);

	double perimetro() const;
	double area() const;

	string getNombre() const;
};

#endif // TRIANGULO_H
