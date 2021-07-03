#include "PilaImplEstatica.h"


template<class T>
PilaImplEstatica<T>::~PilaImplEstatica()
{}


template<class T>
bool PilaImplEstatica<T>::apilar(const T& dato)
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
}


template<class T>
bool PilaImplEstatica<T>::desapilar(T& dato)
{
	if(this->vec.empty())
		return false;
	
	dato = this->vec.back();
	this->vec.pop_back();
	return true;
}


template<class T>
bool PilaImplEstatica<T>::verTope(T& dato) const
{
	if(this->vec.empty())
		return false;
	
	dato = this->vec.back();
	
	return true;
}


template<class T>
bool PilaImplEstatica<T>::vacia() const
{
	return this->vec.empty();
}


template<class T>
void PilaImplEstatica<T>::vaciar()
{
	this->vec.erase(this->vec.begin(), this->vec.end());
}
