#include <iostream>

#include "../TDAPila/PilaImplEstatica.h"

using namespace std;

void ordenarConPilas(int* vector, int ce);


int main()
{
    int ce = 10;
    int vector[ce] = {10, 2, 9, 7, 3, 8, 1, 4, 5, 6};
    
    ordenarConPilas(vector, ce);

    return 0;
}


void ordenarConPilas(int* vector, int ce)
{
    PilaImplEstatica<int> pilaOrd;

    pilaOrd.apilar(vector[0]);

    cout << "elemento desapilado: " << pilaOrd.desapilar() << endl;
}
