#include <iostream>

#include <Pila.h>

using namespace std;


int main()
{
    Pila<int> pila;
    
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    pila.apilar(40);
    pila.apilar(50);
    pila.apilar(60);
    pila.apilar(70);
    pila.apilar(80);
    pila.apilar(90);
    pila.apilar(100);
    pila.apilar(110);
    pila.apilar(120);
    pila.apilar(130);
    pila.apilar(140);
    pila.apilar(150);
    pila.apilar(160);
    pila.apilar(170);
    
    int elem;
    
    while(!pila.vacia())
    {
		pila.desapilar(elem);
		printf("Elem desapilado: %d\n", elem);
	}
    
    
    return 0;
}
