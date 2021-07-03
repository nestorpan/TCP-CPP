#ifndef PILAIMPLESTATICA_H
#define PILAIMPLESTATICA_H

#include <vector>

#include "Pila.h"

using namespace std;


template<class T>
class PilaImplEstatica : public Pila<T>
{
private:
	vector<T> vec;
	
public:
	~PilaImplEstatica();
	
	bool apilar(const T& dato);
	bool desapilar(T& dato);
	bool verTope(T& dato) const;
	bool vacia() const;
	void vaciar();
};


#endif // PILAIMPLESTATICA_H
