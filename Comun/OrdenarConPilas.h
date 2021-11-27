#ifndef ORDENARCONPILAS_H
#define ORDENARCONPILAS_H

#include "../TDAPila/Pila.h"
#include "../TDAPila/PilaImplEstatica.h"
#include "../TDAPila/PilaImplDinamica.h"


template <class T>
void apilarCuandoElemEsMayor(Pila<T>& pilaOrd, const T& elem)
{
	PilaImplEstatica<T> pilaAux;

	do
	{
		pilaAux.apilar(pilaOrd.desapilar());
	}
	while(!pilaOrd.vacia() && elem > pilaOrd.verTope());

	pilaOrd.apilar(elem);
	
	while(!pilaAux.vacia())
		pilaOrd.apilar(pilaAux.desapilar());
}


template <class T>
void ordenarConPilas(T* vector, int ce)
{
	PilaImplDinamica<T> pilaOrd;
	
	pilaOrd.apilar(vector[0]);

	for(int i = 1; i < ce; i++)
	{
		if(vector[i] <= pilaOrd.verTope())
			pilaOrd.apilar(vector[i]);
		else
			apilarCuandoElemEsMayor<T>(pilaOrd, vector[i]);
	}

	for(int i = 0; i < ce; i++)
		vector[i] = pilaOrd.desapilar();
}


#endif // ORDENARCONPILAS_H
