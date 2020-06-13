#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "Figura.h"


class Pentagono : public Figura
{
	private:
		double lado;
		
	public:
		Pentagono(double lado);
		
		double perimetro() const;
		double area() const;
};


#endif // PENTAGONO_H
