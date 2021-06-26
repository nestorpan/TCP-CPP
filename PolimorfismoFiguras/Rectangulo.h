#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Punto.h"
#include "Figura.h"


class Rectangulo : public Figura
{
private:
	Punto p1;
	Punto p2;
	Punto p3;
	Punto p4;
	
	bool esRectangulo() const;
	
public:
	Rectangulo(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4);
	
	double perimetro() const;
	double area() const;
};

#endif // RECTANGULO_H
