#ifndef PILA_H
#define PILA_H

#include <iostream>

using namespace std;


template<class T>
class Pila
{
public:
	virtual ~Pila() = default;
	
	virtual void apilar(const T& dato) = 0;
	virtual T desapilar() = 0;
	virtual const T& verTope() = 0;
	virtual bool vacia() = 0;
	virtual bool llena() = 0;
	virtual void vaciar() = 0;
};


#endif // PILA_H
