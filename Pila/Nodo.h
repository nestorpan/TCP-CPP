#ifndef NODO_H
#define NODO_H

template <class T>
class PilaImplDinamica;


template <class T>
class Nodo
{
private:
	T elemento;
	Nodo<T>* sig;

public:
	Nodo(const T& elemento);

	friend class PilaImplDinamica<T>;
};


template <class T>
Nodo<T>::Nodo(const T& elemento)
{
	this->elemento = elemento;
	this->sig = nullptr;
}


#endif // NODO_H
