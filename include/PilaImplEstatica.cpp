#include <PilaImplEstatica.h>


template <class T>
PilaImplEstatica<T>::PilaImplEstatica()
: tope(-1)
{}


template <class T>
bool PilaImplEstatica<T>::apilar(const T& dato)
{
	if(this->tope + 1 == TAM_PILA)
		return false;
	
	this->tope++;
	this->vecPila[this->tope] = dato;
	
	return true;
}


template <class T>
bool PilaImplEstatica<T>::desapilar(T& dato)
{
	if(this->tope == -1)
		return false;

	dato = this->vecPila[this->tope];
	this->tope--;
	
	return true;
}


template <class T>
bool PilaImplEstatica<T>::verTope(T& dato)
{
	if(this->tope == -1)
		return false;

	dato = this->vecPila[this->tope];
	
	return true;
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
