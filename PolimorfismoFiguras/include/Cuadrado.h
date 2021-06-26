#ifndef CUADRADO _H
#define CUADRADO _H

#include "Figura.h"

class Cuadrado : public Figura
{
    private:
        double lado;

    public:
        Cuadrado(double lado);

        /// double perimetro();
        double area();
};

#endif // CUADRADO _H
