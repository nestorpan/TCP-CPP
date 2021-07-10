#ifndef PILA_H
#define PILA_H

#include <string>
#include <cstring>

#include "PilaException.h"

using namespace std;


template<class T>
class Pila
{
public:
	virtual ~Pila() {};
	
	virtual bool apilar(const T& dato) = 0;
	virtual bool desapilar(T& dato) = 0;
	virtual bool verTope(T& dato) const = 0;
	virtual bool vacia() const = 0;
	virtual void vaciar() = 0;
};


#endif // PILA_H
