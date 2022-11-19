#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include <new>
#include "Nodo.h"
#include "Pila.h"

using namespace std;


template <class T>
class PilaImplDinamica : public Pila<T>
{
private:
	Nodo<T>* tope;

public:
	PilaImplDinamica();
	PilaImplDinamica(const PilaImplDinamica<T>& otra);
	~PilaImplDinamica();

	PilaImplDinamica& operator =(const PilaImplDinamica& otra);

	void apilar(const T& elemento);
	T desapilar();
	T getTope() const;
	bool vacia() const;
	bool llena() const;
	void vaciar();
};


template <class T>
PilaImplDinamica<T>::PilaImplDinamica()
{
	tope = NULL;
}


template <class T>
PilaImplDinamica<T>::PilaImplDinamica(const PilaImplDinamica<T>& otra)
{
	if(otra.tope == nullptr)
	{
		this->tope = nullptr;
		return;
	}
	
	Nodo<T>* act = otra.tope;
	Nodo<T>* actNue;

	tope = new Nodo<T>(act);
	actNue = getTope;
	act = act->sig;
	while(act != nullptr)
	{
		actNue->sig = new Nodo<T>(act);
		act = act->sig;
		actNue = actNue->sig;
	}
}


template <class T>
PilaImplDinamica<T>::~PilaImplDinamica()
{
	vaciar();
}


template <class T>
PilaImplDinamica<T>& PilaImplDinamica<T>::operator =(const PilaImplDinamica<T>& otra)
{
	if(this == &otra)
		return *this;

	vaciar();

	if(otra.tope == nullptr)
	{
		this->tope = nullptr;
		return *this;
	}
	
	Nodo<T>* act = otra.tope;
	Nodo<T>* actNue;

	tope = new Nodo<T>(act);
	actNue = tope;
	act = act->sig;
	while(act != nullptr)
	{
		actNue->sig = new Nodo<T>(act);
		act = act->sig;
		actNue = actNue->sig;
	}

	return *this;
}


template <class T>
void PilaImplDinamica<T>::apilar(const T& elemento)
{
	Nodo<T>* nuevo;
	
	try
	{
		nuevo = new Nodo<T>(elemento);
	}
	catch(bad_alloc& e)
	{
		throw ContenedorLlenoException("No hay memoria disponible.");
	}
	
	nuevo->sig = tope;
	tope = nuevo;
}


template <class T>
T PilaImplDinamica<T>::desapilar()
{
	if(tope == nullptr)
		throw ContenedorLlenoException("La pila está vacía.");
	
	Nodo<T>* nae = tope;
	T elemento = nae->elemento;
	tope = tope->sig;
	delete nae;

	return elemento;
}


template <class T>
T PilaImplDinamica<T>::getTope() const
{
	if(tope == nullptr)
		throw ContenedorLlenoException("La pila está vacía.");
	
	return tope->elemento;
}


template <class T>
bool PilaImplDinamica<T>::vacia() const
{
	return tope == nullptr;
}


template <class T>
bool PilaImplDinamica<T>::llena() const
{
	return false;
}


template <class T>
void PilaImplDinamica<T>::vaciar()
{
	Nodo<T>* nae;

	while(tope != nullptr)
	{
		nae = tope;
		tope = tope->sig;
		delete nae;
	}
}


#endif // PILAIMPLDINAMICA_H
