#ifndef PILAFACTORY_H
#define PILAFACTORY_H

#include "Pila.h"
#include "PilaImplEstatica.h"
#include "PilaImplDinamica.h"


typedef enum
{
	PILA_ESTATICA,
	PILA_DINAMICA
}
TipoPila;


class PilaFactory
{
public:
	template <class T>
	static Pila<T>* crearPila(TipoPila tipoPila);
};


template <class T>
Pila<T>* PilaFactory::crearPila(TipoPila tipoPila)
{
	switch (tipoPila)
	{
		case PILA_ESTATICA:
			return new PilaImplEstatica<T>();

		case PILA_DINAMICA:
			return new PilaImplDinamica<T>();

		default:
			return NULL;
	}
}


#endif // PILAFACTORY_H
