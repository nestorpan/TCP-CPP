#include <iostream>
#include "Circulo.h"

using namespace std;


const float Circulo::PI = 3.141592653589793;


Circulo::Circulo(const string& nombre, float radio)
: Figura(nombre), radio(radio)
{}


Circulo::~Circulo()
{
    cout << "Destruyendo circulo " << this->getNombre() << endl;
}


float Circulo::area() const
{
    return PI * radio * radio;
}


float Circulo::perimetro() const
{
    return 2 * PI * radio;
}
