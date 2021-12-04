#ifndef SPTR_H
#define SPTR_H

#include <iostream>

#include "Contador.h"

using namespace std;


template <class T>
class Sptr
{
private:
	Contador<T>* contador;	

public:
	Sptr() : contador(nullptr) {};

	Sptr(T* obj) : contador(new Contador<T>(obj)) {};

	Sptr(const Sptr<T>& sptr) : contador(sptr.contador)
	{
		if (this->contador != nullptr)
			this->contador->contador++;
	};
	
	~Sptr()
	{
		if (this->contador != nullptr)
		{
			this->contador->contador--;
			if(this->contador->contador == 0)
			{
				delete this->contador->obj;
				delete this->contador;
			}
		}
	}

	Sptr& operator =(const Sptr& sptr)
	{
		cout << "Operator =" << endl;
		
		if(this == &sptr)
			return *this;
				
		if(this->contador != nullptr)
		{
			this->contador->contador--;
			
			if(this->contador->contador == 0)
			{
				delete this->contador->obj;
				delete this->contador;
			}
		}

		this->contador = sptr.contador;

		if(this->contador != nullptr)
			this->contador->contador++;

		return *this;
	}

	T& operator *()
	{
		if(this->contador == nullptr)
			throw "Sptr nulo";
		
		return *(this->contador->obj);
	}

	T* operator ->()
	{
		if(this->contador == nullptr)
			throw "Sptr nulo";
		
		return this->contador->obj;
	}
};


#endif // SPTR_H
