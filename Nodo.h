#ifndef NODO_H
#define NODO_H


template <class T>
class Nodo
{
private:
	T dato;
	Nodo* sig;
	
public:
	Nodo(const T& dato);
	
	friend class PilaImplDinamica;
};


#endif // NODO_H
