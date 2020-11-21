#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include "Nodo.h"
#include <Pila.h>


template <class T>
class PilaImplDinamica : public Pila<T>
{
    private:
        Nodo<T>* pila;

    public:
        PilaImplDinamica();
        ~PilaImplDinamica();

        bool apilar(const T& dato);
        bool desapilar(T& dato);
        bool verTope(T& dato);
        bool vacia();
        bool llena();
        void vaciar();
};


#endif // PILAIMPLDINAMICA_H
