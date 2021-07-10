#ifndef PILAFACTORY_H
#define PILAFACTORY_H

#include "../../StringUtils/include/StringUtils.h"
#include "PilaImplEstatica.h"
#include "PilaImplDinamica.h"

template <class T>
Pila<T>* pilaFactory(const string& tipo)
{
	string tipoLower = toLower(tipo);

	if(tipoLower == "estatica")
		return new PilaImplEstatica<T>;

	if(tipoLower == "dinamica")
		return new PilaImplDinamica<T>;

	throw PilaException("Tipo de pila desconocido.");
}


#endif // PILAFACTORY_H
