#include <string>
#include <iostream>
#include "Triangulo.h"

using namespace std;


Triangulo::Triangulo(const string& nombre, float base, float altura, float lado1, float lado2, float lado3)
: Figura(nombre), base(base), altura(altura), lado1(lado1), lado2(lado2), lado3(lado3)
{}


Triangulo::~Triangulo()
{
    cout << "Destruyendo triangulo " << this->getNombre() << endl;
}


float Triangulo::area() const
{
    return (base * altura) / 2;
}


float Triangulo::perimetro() const
{
    return lado1 + lado2 + lado3;
}
