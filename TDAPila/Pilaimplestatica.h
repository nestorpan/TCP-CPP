#ifndef PILAIMPLESTATICA_H
#define PILAIMPLESTATICA_H

#include <stdexcept>

#include "Pila.h"

using namespace std;


template <class T>
class PilaImplEstatica : public Pila<T>
{
    private:
        static const int CANT_ELEMENTOS = 10;

        T elementos[CANT_ELEMENTOS];
        int tope;

    public:
        PilaImplEstatica()
        {
            this->tope = -1;
        }

        void apilar(const T& elem) override
        {
            if (this->tope == CANT_ELEMENTOS - 1)
                throw overflow_error("La pila está llena");

            tope++;
            elementos[tope] = elem;
        }


        T desapilar() override
        {
            if (tope == -1)
                throw underflow_error("La pila esta vacia");

            return elementos[tope--];
        }


        bool vacia() const override
        {
            return tope == -1;
        }


        void vaciar() override
        {
            tope = -1;
        }


        const T& verTope() const override
        {
            if (tope == -1)
                throw underflow_error("La pila esta vacia");

            return elementos[tope];
        }
    };


#endif // PILAIMPLESTATICA_H
