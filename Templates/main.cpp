#include <iostream>
#include "Cadena.h"

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
    cout << "a: " << a << ", b: " << b << endl;

    intercambiar<float>(c, d);
    cout << "c: " << c << ", d: " << d << endl;

    intercambiar<Cadena>(c1, c2);
    cout << "c1: " << c1 << ", c2: " << c2 << endl;

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
