#include <iostream>
#include <fstream>
#include "Figura.h"
#include "FiguraFactory.h"

#define ARG_TXT_ENT 1

using namespace std;


void imprimirFigura(const Figura& figura);


int main(int argc, char* argv[])
{
/*
    Cuadrado cuadrado(5);
    imprimirFigura(cuadrado);
    
    Circulo circulo(4);
    imprimirFigura(circulo);
    
    Pentagono pentagono(3);
    imprimirFigura(pentagono);
*/  

    filebuf fb;
    fb.open(argv[ARG_TXT_ENT], ios::in);
    istream figurasA(&fb);
    Cadena linea;
    FiguraFactory factory;
    Figura* figura;
    vector<Figura*> figurasV;
    
    while(figurasA.peek() != EOF)
    {
        figurasA >> linea;
        
        figura = factory.crearFigura(linea);
        
        figurasV.push_back(figura);
    }
    
    for(vector<Figura*>::iterator i = figurasV.begin(); i < figurasV.end(); ++i)
        imprimirFigura(**i);
    
    fb.close();
    
    for(vector<Figura*>::iterator i = figurasV.begin(); i < figurasV.end(); ++i)
        delete *i;
    
    return 0;
}


void imprimirFigura(const Figura& figura)
{
    cout << "Perimetro del " << figura.getNombre() << " es: " << figura.perimetro() << endl;
    cout << "Area del " << figura.getNombre() << " es: " << figura.area() << endl;
}
