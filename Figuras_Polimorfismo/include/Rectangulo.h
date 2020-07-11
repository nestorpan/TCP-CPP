#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"


class Rectangulo : public Figura
{
	private:
		double lado1;
		double lado2;
	
	public:
		Rectangulo(double lado1 = 1.0, double lado2 = 1.0);
		
		double perimetro() const;
		double area() const;
};


#endif // RECTANGULO_H
