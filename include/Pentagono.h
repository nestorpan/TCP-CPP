#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "Figura.h"


class Pentagono : public Figura
{
private:
	double lado;
	
public:
	Pentagono(double lado);
	
	string nombre() const;
	double perimetro() const;
	double area() const;
	double apotema() const;
};


#endif // PENTAGONO_H
