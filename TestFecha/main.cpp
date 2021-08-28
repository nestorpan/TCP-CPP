#include <iostream>
#include "../Fecha/Fecha.h"

using namespace std;

int main()
{
    int e;
    cout << "Hello world! holaaaaa " << 100 << endl;

    cout << "Ingrese un valor entero --> ";
    cin >> e;

    cout << "El valor del entero ingresado es: " << e << endl;


    const Fecha hoy(28, 8 , 2021);
    Fecha manana = hoy.sumarDias(1);


    return 0;
}
