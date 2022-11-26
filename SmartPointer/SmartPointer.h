#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>
#include "NullPointerException.h"

using namespace std;


template <class T>
class Contador
{
private:
	unsigned contador;
	T* pObj;

public:
	Contador(T* pObj) { this->pObj = pObj; contador = 1; };
	~Contador() { delete pObj; };

	void operator ++(int) { contador++; cout << "Contador++: " << contador << endl; };

	void operator --(int)
	{
		contador--;

		cout << "Contador--: " << contador << endl;

		if(contador == 0)
			delete this;
	};

	inline T* getObj() const { return pObj; };
};


template <class T>
class SPtr
{
private:
	Contador<T>* contador;

public:
	inline SPtr() { contador = nullptr; };
	inline SPtr(T* pObj) { contador = new Contador<T>(pObj); };


	SPtr(const SPtr<T>& otro)
	{
		cout << "SPtr(const SPtr<T>& otro)" << endl;

		contador = otro.contador;

		if(contador)
			(*contador)++;
	};


	~SPtr()
	{
		if(contador)
			(*contador)--;
	};


	SPtr<T>& operator =(const SPtr<T>& sptr)
	{
		cout << "SPtr<T>& operator =(const SPtr<T>& sptr)" << endl;

		if(this->contador)
			(*this->contador)--;

		this->contador = sptr.contador;

		if(this->contador)
			(*this->contador)++;

		return *this;
	};

/*
	SPtr<T>& operator =(T* pObj)
	{
		if(this->contador)
			(*this->contador)--;

		if(pObj)
			this->contador = new Contador<T>(pObj);
		else
			this->contador = nullptr;

		return *this;
	};
*/

	T* operator ->() const
	{
		if(!contador)
			throw NullPointerException("SPtr: Op ->.");

		return contador->getObj();
	};


	T& operator *() const
	{
		if(!contador)
			throw NullPointerException("SPtr: Op *.");

		return *(contador->getObj());
	};
};


#endif // SMART_POINTER_H
