#include <iostream>
#include <fstream>
#include <string.h>

//#include "../Cadena/Cadena.h"
#include "Cadena.h"
#include "locale.h"

using namespace std;


void func1();


int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "Spanish");

///    func1();

    filebuf fb;
	fb.open(argv[1], ios::in);
	istream emplIS(&fb);

    Cadena linea;

    while(!emplIS.eof())
    {
        emplIS >> linea;
        //char c = linea.getCad()[strlen(linea.getCad())];
        if (!linea.vacia()) {
            cout << linea << endl;
        }
    }

    fb.close();

    return 0;

}


void func1()
{
    Cadena c1("Hola"), c2("que"), c3("tal");


    Cadena saludo = c1 + ", ¿" + c2 + ' ' + c3 + "? - " + 15 + ' ' + 29;

    Cadena saludo2 = "¡¡" + c1 + "!!";

    cout << saludo << endl;
    cout << saludo2 << endl;


	const char* vConcat = new char[15];
	//strcpy(vConcat, "sasasas");

	Cadena pepe = Cadena(vConcat); ///Llama al constructor privado que no copia la cadena.

}
