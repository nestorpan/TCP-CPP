#include <PilaImplDinamica.h>


template <class T>
PilaImplDinamica<T>::PilaImplDinamica()
: pila(NULL)
{}


template <class T>
PilaImplDinamica::~PilaImplDinamica()
{
	this->vaciar();
}


template <class T>
bool PilaImplDinamica<T>::apilar(const T& dato)
{
	Nodo* nue = new Nodo(dato);

	nue->sig = this->pila;
	this->pila = nue;

	return true;
}


template <class T>
bool PilaImplDinamica<T>::desapilar(T& dato)
{
	if(!this->pila)
		return false;

	Nodo* nae = this->pila;
	this->pila = nae->sig;
	dato = nae->dato;
	delete nae;
	return true;
}


template <class T>
bool PilaImplDinamica<T>::verTope(T& dato)
{
	if(!this->pila)
		return false;

	dato = this->pila->dato;

	return true;
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
	Nodo* nae;
	while(this->pila)
	{
		nae = this->pila;
		this->pila = nae->sig;
		delete nae;
	}
}


template class PilaImplDinamica<int>;
