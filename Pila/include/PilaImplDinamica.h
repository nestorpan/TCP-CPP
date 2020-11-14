#ifndef PILAIMPLDINAMICA_H
#define PILAIMPLDINAMICA_H

#include <Nodo.h>


template <class T>
class PilaImplDinamica : Pila<T>
{
    private:
        Nodo* pila;

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
