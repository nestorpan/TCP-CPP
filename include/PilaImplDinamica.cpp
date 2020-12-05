#include <stddef.h>
#include <new>
#include <Nodo.h>
#include <PilaException.h>
#include <PilaImplDinamica.h>

using namespace std;


template <class T>
PilaImplDinamica<T>::PilaImplDinamica()
: pila(NULL)
{}


template <class T>
PilaImplDinamica<T>::~PilaImplDinamica()
{
	this->vaciar();
}


template <class T>
void PilaImplDinamica<T>::apilar(const T& dato)
{
	Nodo<T>* nue;
	
	try
	{
		nue = new Nodo<T>(dato);
	}
	catch(bad_alloc& ex)
	{
		throw PilaException("Pila llena");
	}
	
	nue->sig = this->pila;
	this->pila = nue;
}


template <class T>
T PilaImplDinamica<T>::desapilar()
{
	if(!this->pila)
		throw PilaException("Pila llena");
	
	Nodo<T>* nae = this->pila;
	this->pila = nae->sig;
	T dato = nae->dato;
	delete nae;
	return dato;
}


template <class T>
const T& PilaImplDinamica<T>::verTope()
{
	if(!this->pila)
		throw PilaException("Pila vacia");
	
	return this->pila->dato;
}


template <class T>
bool PilaImplDinamica<T>::vacia()
{
	return !this->pila;
}


template <class T>
bool PilaImplDinamica<T>::llena()
{
	return false;
}


template <class T>
void PilaImplDinamica<T>::vaciar()
{
	Nodo<T>* nae;
	while(this->pila)
	{
		nae = this->pila;
		this->pila = nae->sig;
		delete nae;
	}
}


template class PilaImplDinamica<int>;
