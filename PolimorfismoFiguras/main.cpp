#include <vector>
#include <iostream>

#include "Triangulo.h"
#include "Circulo.h"
#include "Rectangulo.h"

using namespace std;


void imprimirAreaYPerimetroFiguras(vector<Figura*>& vecFiguras);


int main()
{
    Triangulo tri(Punto(2, 2), Punto(4.3, 7), Punto(6.8, 2));
    Circulo cir(Punto(), 5);
    Rectangulo rect(Punto(4, 8), Punto(8, 8), Punto(4, 1), Punto(8, 1));
    
    vector<Figura*> vecFiguras;
    vecFiguras.push_back(&tri);
    vecFiguras.push_back(&cir);
    vecFiguras.push_back(&rect);
    
    imprimirAreaYPerimetroFiguras(vecFiguras);
    
    return 0;
}


void imprimirAreaYPerimetroFiguras(vector<Figura*>& vecFiguras)
{
	for(vector<Figura*>::iterator i = vecFiguras.begin(); i < vecFiguras.end(); i++)
		cout << "Area: " << (*i)->area() << "; Perímetro: " << (*i)->perimetro() << endl;
}












