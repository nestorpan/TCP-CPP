#include <iostream>
#include <vector>

#include "../Cadena/Cadena.h"
#include "../Pila/PilaFactory.h"

using namespace std;


template <class T>
void ordenarConPilas(vector<T>& vec)
{
    Pila<int>* pilaOrd = pilaFactory<T>("dinamica");
    Pila<int>* pilaAux = pilaFactory<T>("estatica");
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
    vector<int> vec;
    
    srand(time(nullptr));
    
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 100);
    }
	
	cout << "Antes de ordenar:" << endl;
	
	for(vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
        cout << *i << endl;
           
    ordenarConPilas<int>(vec);
	
	cout << endl;
	
	cout << "Despues de ordenar" << endl;;
	
	for(vector<int>::iterator i = vec.begin(); i < vec.end(); i++)
        cout << *i << endl;
	
    return 0;
}






