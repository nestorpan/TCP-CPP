#ifndef NODO_H
#define NODO_H

template<class T>
class PilaImplDinamica;


template<class T>
class Nodo
{
private:
	T dato;
	Nodo* sig;
	
public:
	Nodo(const T& dato) : dato(dato) {};
	
	friend class PilaImplDinamica<T>;
};


#endif // NODO_H
