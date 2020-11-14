#ifndef PILA_H
#define PILA_H


template<class T>
class Pila
{
public:
	virtual bool apilar(const T& dato) = 0;
	virtual bool desapilar(T& dato) = 0;
	virtual bool verTope(T& dato) = 0;
	virtual bool vacia() = 0;
	virtual bool llena() = 0;
	virtual void vaciar() = 0;
};


#endif // PILA_H
