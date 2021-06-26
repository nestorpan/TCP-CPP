#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

using namespace std;

class Figura
{
    public:
        virtual double perimetro() const = 0;
        virtual double area() const = 0;
        virtual string getNombre() const = 0;

        string print() const;

};

#endif // FIGURA_H
