#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"


class Cuadrado : public Figura
{
	private:
		double lado;
	
	public:
		Cuadrado(double lado = 1.0);
		
		double perimetro() const;
		double area() const;
};


#endif // CUADRADO_H
