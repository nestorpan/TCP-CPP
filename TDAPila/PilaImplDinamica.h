#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include "../Nodo/Nodo.h"
#include "../Comun/ContenedorVacioException.h"


template <class T>
class PilaImplDinamica : public Pila<T>
{
private:
    Nodo<T>* listaNodos;

public:
    PilaImplDinamica()
    {
        listaNodos = NULL;
    }


    ~PilaImplDinamica()
    {
        while(listaNodos)
        {
            Nodo<T>* nae = listaNodos;
            listaNodos = listaNodos->sig;
            delete nae;
        }
    }


    void apilar(const T& elem) override
    {
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo->elem = elem;
        nuevo->sig = listaNodos;
        listaNodos = nuevo;
    }


    T desapilar() override
    {
        if(!listaNodos)
            throw ContenedorVacioException("La pila está vacía.");
        
        Nodo<T>* nae = listaNodos;
        listaNodos = nae->sig;
        T elem = nae->elem;
        delete nae;
        return elem;
    }


    const T& verTope() const override
    {
        if(!listaNodos)
            throw ContenedorVacioException("La pila está vacía.");
        
        return listaNodos->elem;
    }


    bool vacia() const override
    {
        return !listaNodos;
    }


    void vaciar() override
    {
        while(listaNodos)
        {
            Nodo<T>* nae = listaNodos;
            listaNodos = listaNodos->sig;
            delete nae;
        }
    }
};


#endif // PILAIMPLDINAMICA_H
