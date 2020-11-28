#include <iostream>
#include <Pila.h>
#include <PilaImplDinamica.h>

#define TAM_V 10

using namespace std;


void apilarNumerosYEliminarPila(int* v, Pila<int>* pila);


int main()
{
    PilaImplDinamica<int>* pila = new PilaImplDinamica<int>;

    int v[TAM_V] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    apilarNumerosYEliminarPila(v, pila);

    return 0;
}


void apilarNumerosYEliminarPila(int* v, Pila<int>* pila)
{
	for(int i = 0; i < TAM_V; i++)
		pila->apilar(v[i]);

	delete pila;
}
