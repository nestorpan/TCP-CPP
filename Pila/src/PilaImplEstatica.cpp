#include <PilaImplEstatica.h>
#include <PilaException.h>

template <class T>
PilaImplEstatica<T>::PilaImplEstatica()
: tope(-1)
{}


template <class T>
void PilaImplEstatica<T>::apilar(const T& dato)
{
	if(this->tope + 1 == TAM_PILA)
		throw PilaException("Pila llena");

	this->tope++;
	this->vecPila[this->tope] = dato;
}


template <class T>
T PilaImplEstatica<T>::desapilar()
{
    if(this->tope == -1)
		throw PilaException("Pila vacia");

	T dato = this->vecPila[this->tope];
	this->tope--;

	return dato;
}


template <class T>
const T& PilaImplEstatica<T>::verTope()
{
	if(this->tope == -1)
		throw PilaException("Pila vacia");

	return this->vecPila[this->tope];
}


template <class T>
bool PilaImplEstatica<T>::vacia()
{
	return this->tope == -1;
}


template <class T>
bool PilaImplEstatica<T>::llena()
{
	return this->tope + 1 == TAM_PILA;
}


template <class T>
void PilaImplEstatica<T>::vaciar()
{
	this->tope = -1;
}


template class PilaImplEstatica<int>;
