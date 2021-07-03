#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include <new>

#include "Nodo.h"
#include "Pila.h"

using namespace std;


template<class T>
class PilaImplDinamica : public Pila<T>
{
private:
	Nodo<T>* pila;
	
public:
	PilaImplDinamica() : pila(nullptr) {};
	~PilaImplDinamica()	{ this->vaciar(); };
	
	
	bool apilar(const T& dato)
	{
		Nodo<T>* nue;
		
		try
		{
			nue = new Nodo<T>(dato);
		}
		catch(bad_alloc& e)
		{
			return false;
		}
		
		nue->sig = this->pila;
		this->pila = nue;
		
		return true;
	};
	
	
	bool desapilar(T& dato)
	{
		if(!this->pila)
			return false;
		
		Nodo<T>* nae = pila;
		dato = nae->dato;
		this->pila = nae->sig;
		delete nae;
		return true;
	}
	
	
	bool verTope(T& dato) const
	{
		if(!this->pila)
			return false;
		
		dato = this->pila->dato;
		return true;
	}
	
	
	bool vacia() const { return !this->pila; };
	
	
	void vaciar()
	{
		Nodo<T>* nae;
		
		while(this->pila)
		{
			nae = this->pila;
			this->pila = nae->sig;
			delete nae;
		}
	};
};


#endif // PILAIMPLDINAMICA_H
