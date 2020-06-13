#include <iostream>

#include "Cuadrado.h"
#include "Circulo.h"
#include "Pentagono.h"


using namespace std;


void imprimirFigura(const Figura& figura);


int main()
{
    Cuadrado cuadrado(5);
    imprimirFigura(cuadrado);
    
    Circulo circulo(4);
    imprimirFigura(circulo);
    
    Pentagono pentagono(3);
    imprimirFigura(pentagono);
    
    return 0;
}


void imprimirFigura(const Figura& figura)
{
    cout << "Perimetro del " << figura.getNombre() << " es: " << figura.perimetro() << endl;
    cout << "Area del " << figura.getNombre() << " es: " << figura.area() << endl;
}
