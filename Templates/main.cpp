#include <iostream>
#include <queue>
#include <PilaImplDinamica.h>
#include <PilaImplEstatica.h>

#define CANT_ELEM 20000
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
		pila.desapilar(dato);
		
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
		pila2.desapilar(dato);
		
		if(cont < CANT_A_MOSTRAR)
		{
			cout << dato << endl;
			cont++;
		}
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
	
    T frente, temp, tope;
    
    frente = datos.front();
    
//    cout << "Frente: " << frente << endl;
    
    pilaOrd.apilar(frente);
    datos.pop();
	
	while(!datos.empty())
	{
		frente = datos.front();
		
//		cout << "Frente: " << frente << endl;
		
		datos.pop();
		
		pilaOrd.verTope(tope);
		
		if(frente < tope)
			pilaOrd.apilar(frente);
		else
		{
			do
			{
				pilaOrd.desapilar(temp);
				pilaAux.apilar(temp);
				pilaOrd.verTope(tope);
			}
			while(!pilaOrd.vacia() && frente > tope);
			
			pilaOrd.apilar(frente);
			
			while(!pilaAux.vacia())
			{
				pilaAux.desapilar(temp);
				pilaOrd.apilar(temp);
			}
		}	
	}
}
