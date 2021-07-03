#include <iostream>

#include "../Cadena/Cadena.h"
#include "../Pila/PilaImplDinamica.h"


using namespace std;


int main()
{
    PilaImplDinamica<Cadena> pilaDin;
    
    Pila<Cadena>& pila = pilaDin;
    
    pila.apilar("Hola");
    pila.apilar("que");
    pila.apilar("tal");
    pila.apilar('?');
    
    Cadena cad;
    while(!pila.vacia())
    {
		pila.desapilar(cad);
		cout << cad << ' ';
    }
	
    return 0;
}
