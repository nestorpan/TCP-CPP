#ifndef PILAIMPLESTATICA_H
#define PILAIMPLESTATICA_H

#include "Pila.h"

#define TAM_PILA 100


template<class T>
class PilaImplEstatica : public Pila<T>
{
private:
	T vecPila[TAM_PILA];
	int tope;
	
public:
	PilaImplEstatica();
	
	bool apilar(const T& dato);
	bool desapilar(T& dato);
	bool verTope(T& dato);
	bool vacia();
	bool llena();
	void vaciar();
};


#endif // PILAIMPLESTATICA_H
