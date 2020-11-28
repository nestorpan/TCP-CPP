#include <iostream>
#include <queue>
#include <PilaImplDinamica.h>
#include <PilaImplEstatica.h>
#include <time.h>

#define CANT_ELEM 5
#define CANT_A_MOSTRAR 100

using namespace std;

template <class T>
void intercambiar(T& a, T& b);

queue<int> generarColaRandom(unsigned cantElem);

template <class T>
void ordenarConPilas(queue<T> datos, Pila<T>& pilaOrd);

int main()
{
    /*
    int a = 5, b = 8;
    float c = 5.5, d = 8.8;
    Cadena c1("Hola");
    Cadena c2("Hola2");
*/
//    intercambiar<int>(a, b);
//    cout << "a: " << a << ", b: " << b << endl;

//    intercambiar<float>(c, d);
//    cout << "c: " << c << ", d: " << d << endl;

//    intercambiar<Cadena>(c1, c2);
//    cout << "c1: " << c1 << ", c2: " << c2 << endl;


//    PilaImplEstatica<float> pila;


//    PilaImplEstatica<Cadena> pila;
    /*
    pila.apilar("Cadena 1");
    pila.apilar("Cadena 2");
    pila.apilar("Cadena 3");
    char vec[100];
    for(int i = 0; i < 10; i++) {
        itoa(i,vec,10);
        pila.apilar(Cadena((const char*)"Cadena ")+(const char*)vec);
    }

    for(Cadena i = 0.5; i < 10.5; i++) {
        pila.apilar(i);
    }
    Cadena dato;
    while(!pila.vacia())
    {
		pila.desapilar(dato);
		cout << dato << endl;
    }
*/

/*
    int a = 5, b = 8;
    float c = 5.5, d = 8.8;

    intercambiar<int>(a, b);
    cout << "a: " << a << ", b: " << b << endl;

    intercambiar<float>(c, d);
    cout << "c: " << c << ", d: " << d << endl;
*/

    queue<int> qRandom = generarColaRandom(CANT_ELEM);

	queue<int> qRandomCopy = qRandom;

	PilaImplDinamica<int> pila;
	PilaImplEstatica<int> pila2;

	long t1, t2;

	t1 = time(NULL);

	ordenarConPilas(qRandom, pila);

	t2 = time(NULL);

	cout << "Tiempo ordenar dinamica: " << t2 - t1 << endl;

	cout << endl << "Desapilo pila:" << endl;

    int dato;
    int cont = 0;


    while(!pila.vacia())
    {
		dato = pila.desapilar();

		if(cont < CANT_A_MOSTRAR)
		{
			cout << dato << endl;
			cont++;
		}
    }

	t1 = time(NULL);

	ordenarConPilas(qRandomCopy, pila2);

	t2 = time(NULL);

	cout << "Tiempo ordenar estatica: " << t2 - t1 << endl;

	cout << endl << "Desapilo pila2:" << endl;

	cont = 0;
    while(!pila2.vacia())
    {
		dato = pila2.desapilar();

		if(cont < CANT_A_MOSTRAR)
		{
			cout << dato << endl;
			cont++;
		}
    }

    return 0;


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

queue<int> generarColaRandom(unsigned cantElem)
{
	srand(time(NULL));

	queue<int> cola;

	for(unsigned i = 0; i < cantElem; i++)
		cola.push(rand());

	return cola;
}


template <class T>
void ordenarConPilas(queue<T> datos, Pila<T>& pilaOrd)
{
	PilaImplDinamica<T> pilaAux;

    T frente, temp;

    frente = datos.front();

//    cout << "Frente: " << frente << endl;

    pilaOrd.apilar(frente);
    datos.pop();

	while(!datos.empty())
	{
		frente = datos.front();

//		cout << "Frente: " << frente << endl;

		datos.pop();

		if(frente < pilaOrd.verTope())
			pilaOrd.apilar(frente);
		else
		{
			do
			{
				temp = pilaOrd.desapilar();
				pilaAux.apilar(temp);
			}
			while(!pilaOrd.vacia() && frente > pilaOrd.verTope());

			pilaOrd.apilar(frente);

			while(!pilaAux.vacia())
			{
				temp = pilaAux.desapilar();
				pilaOrd.apilar(temp);
			}
		}
	}
}
