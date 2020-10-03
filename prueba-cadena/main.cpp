#include <iostream>
#include <Cadena.h>

using namespace std;

int main()
{
    Cadena cad1("Hola"); // "Hola, que "
    Cadena cad2("que");
    Cadena cad3("tal!!!");

///    const char* cad = "prueba";
///    Cadena prueba(cad);

    Cadena frase = cad1 + ',' + ' ' + cad2 + ' ' + cad3;
///    Cadena frase = cad1 + cad2 + cad3;

    cout << frase << endl;

    cout << "Cant call ==> " << cad1.getCantCall() << endl;

    return 0;
}
