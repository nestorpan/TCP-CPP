#include <iostream>
#include <vector>
#include "Figura.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"


using namespace std;

void calcularFigura(const Figura* figura);


int main()
{
    vector<Figura*> figuras;

    figuras.push_back(new Circulo("Circulo 1", 5));
    figuras.push_back(new Circulo("Circulo 2", 10));
    figuras.push_back(new Cuadrado("Cuadrado 1", 15));
    figuras.push_back(new Cuadrado("Cuadrado 2", 20));
    figuras.push_back(new Triangulo("Triangulo 1", Punto(0,0), Punto(10,10), Punto(20,0)));
    figuras.push_back(new Triangulo("Triangulo 2", Punto(0,0), Punto(20,10), Punto(10,0)));

    for (Figura* figura : figuras)
        calcularFigura(figura);
    
    return 0;
}


void calcularFigura(const Figura* figura)
{
    cout << "Nombre: " << figura->getNombre() << " Area: " << figura->area() << " Perímetro: " << figura->perimetro() << " Apotema: " << figura->apotema() << endl;
}
