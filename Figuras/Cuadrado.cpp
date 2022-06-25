#include <string>
#include <iostream>
#include "Cuadrado.h"

using namespace std;


Cuadrado::Cuadrado(const string& nombre, float lado)
: Figura(nombre), lado(lado)
{}


Cuadrado::~Cuadrado()
{
    cout << "Destruyendo cuadrado " << this->getNombre() << endl;
}


float Cuadrado::area() const
{
    return lado * lado;
}


float Cuadrado::perimetro() const
{
    return lado * 4;
}
