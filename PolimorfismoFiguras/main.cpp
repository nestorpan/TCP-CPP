#include <iostream>

#include "Circulo.h"
#include "Cuadrado.h"
#include "Pentagono.h"

using namespace std;


void imprimirDatosFigura(const Figura& figura);


int main()
{
    Circulo circulo(4);
    Cuadrado cuadrado(3);
    Pentagono pentagono(2);
    
 	imprimirDatosFigura(circulo);
 	imprimirDatosFigura(cuadrado);
    imprimirDatosFigura(pentagono);
    
    return 0;
}


void imprimirDatosFigura(const Figura& figura)
{
	cout << "El perimetro " << (figura.getGenero() == 'M'? "del " : "de la ") << figura.getNombre() << " es: " << figura.perimetro() << endl;
    cout << "El area " << (figura.getGenero() == 'M'? "del " : "de la ") << figura.getNombre() << " es: " << figura.area() << endl;
}

