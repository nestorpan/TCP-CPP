#include <iostream>
#include "..\Cadena\Cadena.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "spanish");

    Cadena cad1("Hola, ");
    Cadena cad2("que ");
    Cadena cad3("tal ?");

    //Cadena saludo = " "+ cad3 + "?";
    Cadena saludo = '¡' + cad1 + "!, " + cad2 + " " + cad3 + 22 ;
    cout << saludo << endl;

    return 0;
}
