#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"


class Circulo : public Figura
{
private:
	double radio;
	
public:
	Circulo(double radio);
	
	Cadena nombre() const;
	double perimetro() const;
	double area() const;
	double apotema() const;
};


#endif // CIRCULO_H
