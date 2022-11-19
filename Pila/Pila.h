#ifndef PILA_H
#define PILA_H


template <class T>
class Pila
{
public:
	virtual void apilar(const T& elemento) = 0;
	virtual T desapilar() = 0;
	virtual T getTope() const = 0;
	virtual bool vacia() const = 0;
	virtual bool llena() const = 0;
	virtual void vaciar() = 0;
};


#endif // PILA_H
