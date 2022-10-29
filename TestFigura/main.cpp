#include <iostream>
#include "../Figura/Circulo.h"
#include "../Figura/Cuadrado.h"

using namespace std;

void imprimirFigura(const Figura& figura);


int main()
{
    Circulo circulo(5);
    Cuadrado cuadrado(4);

    imprimirFigura(circulo);
    imprimirFigura(cuadrado);
    
    return 0;
}


void imprimirFigura(const Figura& figura)
{
    cout << "Area: " << figura.area() << endl;
    cout << "Perimetro: " << figura.perimetro() << endl;
}
