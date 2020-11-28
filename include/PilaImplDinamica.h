#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include "Nodo.h"
#include <Pila.h>


template <class T>
class PilaImplDinamica : public Pila<T>
{
private:
	Nodo<T>* pila;
	
public:
	PilaImplDinamica();
	~PilaImplDinamica();
	
	void apilar(const T& dato);
	T desapilar();
	const T& verTope();
	bool vacia();
	bool llena();
	void vaciar();
};


#endif // PILAIMPLDINAMICA_H
