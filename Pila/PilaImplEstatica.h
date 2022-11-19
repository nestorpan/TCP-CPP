#ifndef PILAIMPLESTATICA_H
#define PILAIMPLESTATICA_H

#include "ContenedorLlenoException.h"
#include "ContenedorVacioException.h"
#include "Pila.h"

#define CAP_PILA 100


template <class T>
class PilaImplEstatica : public Pila<T>
{
private:
	T vecElementos[CAP_PILA];
	int tope;

public:
	PilaImplEstatica();

	void apilar(const T& elemento) override;
	T desapilar() override;
	T getTope() const override;
	bool vacia() const override;
	bool llena() const override;
	void vaciar() override;
};


template <class T>
PilaImplEstatica<T>::PilaImplEstatica()
{
	tope = -1;
}


template <class T>
void PilaImplEstatica<T>::apilar(const T& elemento)
{
	if(tope + 1 == CAP_PILA)
		throw ContenedorLlenoException("Pila llena.");

	vecElementos[++tope] = elemento;
}


template <class T>
T PilaImplEstatica<T>::desapilar()
{
	if(tope == -1)
		throw ContenedorLlenoException("La pila está vacía.");

	return vecElementos[tope--];
}


template <class T>
T PilaImplEstatica<T>::getTope() const
{
	if(tope == -1)
		throw ContenedorLlenoException("La pila está vacía.");

	return vecElementos[tope];
}


template <class T>
bool PilaImplEstatica<T>::vacia() const
{
	return tope == -1;
}


template <class T>
bool PilaImplEstatica<T>::llena() const
{
	return tope + 1 == CAP_PILA;
}


template <class T>
void PilaImplEstatica<T>::vaciar()
{
	tope = -1;
}


#endif // PILAIMPLESTATICA_H
