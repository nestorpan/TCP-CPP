#ifndef CONTADOR_H
#define CONTADOR_H

template <class T>
class Sptr;


template <class T>
class Contador
{
private:
	unsigned contador;
	T* obj;

public:
	Contador(T* obj) : contador(1), obj(obj) {};

	friend class Sptr<T>;
};


#endif // CONTADOR_H
