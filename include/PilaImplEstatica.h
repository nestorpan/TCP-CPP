#ifndef PILAIMPLESTATICA_H
#define PILAIMPLESTATICA_H

#include "Pila.h"

#define TAM_PILA 100000


template<class T>
class PilaImplEstatica : public Pila<T>
{
private:
	T vecPila[TAM_PILA];
	int tope;
	
public:
	PilaImplEstatica();
	
	void apilar(const T& dato);
	T desapilar();
	const T& verTope();
	bool vacia();
	bool llena();
	void vaciar();
};


#endif // PILAIMPLESTATICA_H
