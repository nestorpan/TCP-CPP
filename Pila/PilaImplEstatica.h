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
	PilaImplEstatica() {};
	~PilaImplEstatica() {}
	
		
	bool apilar(const T& dato)
	{
		try
		{
			this->vec.push_back(dato);
			return true;
		}
		catch(bad_alloc& e)
		{
			return false;
		}
	};
	
	
	bool desapilar(T& dato)
	{
		if(this->vec.empty())
			return false;
		
		dato = this->vec.back();
		this->vec.pop_back();
		return true;
	};

	
	bool verTope(T& dato) const
	{
		if(this->vec.empty())
			return false;
		
		dato = this->vec.back();
		
		return true;
	};


	bool vacia() const
	{
		return this->vec.empty();
	};

	
	void vaciar()
	{
		this->vec.erase(this->vec.begin(), this->vec.end());
	};
};


#endif // PILAIMPLESTATICA_H
