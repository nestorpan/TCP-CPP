#include <iostream>

#include "../Cadena/Cadena.h"
#include "../Persona/include/Persona.h"
#include "../Persona/include/PersonaBuilder.h"
#include "../Pila/include/PilaImplDinamica.h"
#include "../Pila/include/PilaImplEstatica.h"

using namespace std;

int main()
{
    ///PilaImplDinamica<Persona> pilaDin;
    PilaImplEstatica<Persona> pilaEst;

    ///Pila<Cadena>& pila = pilaEst;
    Pila<Persona>& pila = pilaEst;

    PersonaBuilder pb;
    pb.setApyn("Juan Perez");
    pila.apilar(pb.build());

    pb.setApyn("Juana Garcia");
    pila.apilar(pb.build());
/*
    pila.apilar('?');
    pila.apilar("tal");
    pila.apilar("que");
    pila.apilar("Hola");
*/
    Cadena cad;
    Persona p;

    while(!pila.vacia())
    {
///		pila.desapilar(cad);
///		cout << cad << ' ';
		pila.desapilar(p);
		cout << p.getApyn() << endl;
    }
    cout << endl;
/*
    pila.apilar("Hola");
    if (pila.vacia())
        cout << "NO HAY tope";
    else {
        cout << "HAY tope";
    }
*/
    return 0;
}
