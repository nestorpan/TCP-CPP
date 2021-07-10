#include <iostream>
#include <vector>
#include "time.h"


#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "../Persona/include/Persona.h"
#include "../Persona/include/PersonaBuilder.h"

#include "../Pila/include/PilaFactory.h"

using namespace std;


template <class T>
void ordenarConPilas(vector<T>& vec)
{
    Pila<Persona>* pilaOrd = pilaFactory<T>("dinamica");
    Pila<Persona>* pilaAux = pilaFactory<T>("estatica");
    T tope, dato;

    for(class vector<T>::iterator i = vec.begin(); i < vec.end(); i++)
    {
        pilaOrd->verTope(tope);

        if(pilaOrd->vacia() || *i <= tope)
            pilaOrd->apilar(*i);
        else
        {
            while(!pilaOrd->vacia() && *i > tope)
            {
                pilaOrd->desapilar(dato);
                pilaAux->apilar(dato);
                pilaOrd->verTope(tope);
            }

            pilaOrd->apilar(*i);

            while(!pilaAux->vacia())
            {
                pilaAux->desapilar(dato);
                pilaOrd->apilar(dato);
            }
        }
    }

    vec.erase(vec.begin(), vec.end());

    while(!pilaOrd->vacia())
    {
        pilaOrd->desapilar(dato);
        vec.push_back(dato);
    }

    delete pilaOrd;
    delete pilaAux;
}


int main()
{
    ///vector<int> vec;
    vector<Persona> vec;

    srand(time(nullptr));

    PersonaBuilder pb;

    for(int i = 1; i < 11; i++)
    {
        ///vec.push_back(rand() % 100);
        ///vec.push_back(Persona(rand() % 30, rand()%12, 2020-i));
        pb.setDni(rand() % 100);
        pb.setFNac(Fecha(rand() % 30, 7, 2020-i));
        vec.push_back(pb.build());
    }

	cout << "Antes de ordenar:" << endl;

	for(vector<Persona>::iterator i = vec.begin(); i < vec.end(); i++)
        cout << *i << endl;

    ordenarConPilas<Persona>(vec);

	cout << endl;

	cout << "Despues de ordenar" << endl;;

	for(vector<Persona>::iterator i = vec.begin(); i < vec.end(); i++)
        cout << *i << endl;

    return 0;
}
