#include <iostream>
#include "Figura.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"

using namespace std;


void calcularAreaYPerimetro(const Figura* figura);


int main()
{
    Cuadrado* cuadrado = new Cuadrado("cuadrado de 5", 5);
    Triangulo* triangulo = new Triangulo("un triangulo equilatero de 4", 4, 3.46, 4, 4, 4);
    Circulo* circulo = new Circulo("un circulo de radio 3", 3);

    calcularAreaYPerimetro(cuadrado);
    calcularAreaYPerimetro(triangulo);
    calcularAreaYPerimetro(circulo);

    return 0;
}


void calcularAreaYPerimetro(const Figura* figura)
{
    cout << "Nombre: " << figura->getNombre() << endl;
    cout << "Area: " << figura->area() << endl;
    cout << "Perimetro: " << figura->perimetro() << endl;

    delete figura;
}
