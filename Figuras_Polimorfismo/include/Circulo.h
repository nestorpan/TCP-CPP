#ifndef CIRCULO_H
#define CIRCULO_H


#include "Figura.h"

#define PI 3.14159265359


class Circulo : public Figura
{
	private:
		double radio;
		
	public:
		Circulo(double radio = 1.0);
		~Circulo();
		
		double perimetro() const;
		double area() const;
};


#endif // CIRCULO_H
