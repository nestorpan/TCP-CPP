#include <iostream>

//#include "../Cadena/Cadena.h"
#include "Cadena.h"
#include "locale.h"

using namespace std;


void func1();


int main()
{
    setlocale(LC_CTYPE, "Spanish");

    func1();

    ///...

    return 0;
}


void func1()
{
    Cadena c1("Hola"), c2("que"), c3("tal");


    Cadena saludo = c1 + ", ¿" + c2 + ' ' + c3 + "? - " + 15 + ' ' + 29.25;

    Cadena saludo2 = "¡¡" + c1 + "!!";

    cout << saludo << endl;
    cout << saludo2 << endl;


	const char* vConcat = new char[15];
	//strcpy(vConcat, "sasasas");

	Cadena pepe = Cadena(vConcat); ///Llama al constructor privado que no copia la cadena.

}
