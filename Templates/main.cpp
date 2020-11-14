#include <iostream>
#include "Cadena.h"

#include <PilaImplEstatica.h>

using namespace std;

template <class T>
void intercambiar(T& a, T& b);

int main()
{
    int a = 5, b = 8;
    float c = 5.5, d = 8.8;
    Cadena c1("Hola");
    Cadena c2("Hola2");

    intercambiar<int>(a, b);
//    cout << "a: " << a << ", b: " << b << endl;

    intercambiar<float>(c, d);
//    cout << "c: " << c << ", d: " << d << endl;

    intercambiar<Cadena>(c1, c2);
//    cout << "c1: " << c1 << ", c2: " << c2 << endl;


//    PilaImplEstatica<float> pila;


    PilaImplEstatica<Cadena> pila;
    pila.apilar("Cadena 1");
    pila.apilar("Cadena 2");
    pila.apilar("Cadena 3");

    char vec[100];
    for(int i = 0; i < 10; i++) {
        itoa(i,vec,10);
        pila.apilar(Cadena((const char*)"Cadena ")+(const char*)vec);
    }

/*
    for(Cadena i = 0.5; i < 10.5; i++) {
        pila.apilar(i);
    }
*/
    Cadena dato;
    while(!pila.vacia())
    {
		pila.desapilar(dato);
		cout << dato << endl;
    }

    return 0;
}

template <class T>
void intercambiar(T& a, T& b)
{
	T aux;
	aux = a;
	a = b;
	b = aux;
}
