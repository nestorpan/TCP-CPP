#include <iostream>
#include "../Cadena/Cadena.h"
#include "../Pila/PilaFactory.h"


using namespace std;

void hacerAlgoConUnaPila(Pila<Cadena>* pilaCad);


int main()
{
    Pila<Cadena>* pilaCad = PilaFactory::crearPila<Cadena>(TipoPila::PILA_DINAMICA);

    hacerAlgoConUnaPila(pilaCad);

    delete pilaCad;

    pilaCad = PilaFactory::crearPila<Cadena>(TipoPila::PILA_ESTATICA);

    hacerAlgoConUnaPila(pilaCad);

    delete pilaCad;

    return 0;
}


void hacerAlgoConUnaPila(Pila<Cadena>* pilaCad)
{
    pilaCad->apilar(Cadena("Hola"));
    pilaCad->apilar(Cadena("Mundo"));
    pilaCad->apilar(Cadena("C++"));

    while (!pilaCad->vacia())
    {
        cout << pilaCad->desapilar() << endl;
    }
}
