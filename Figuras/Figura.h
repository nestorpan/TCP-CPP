#ifndef FIGURA_H
#define FIGURA_H

#include "../Cadena/Cadena.h"


class Figura
{
private:
    Cadena nombre;

public:
    Figura(const Cadena& nombre);
	
    const Cadena& getNombre() const;

    virtual double area() const = 0;
    virtual double perimetro() const = 0;
	virtual double apotema() const = 0;
};


#endif // FIGURA_H