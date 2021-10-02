#include <iostream>
#include "..\Cadena\Cadena.h"
#include <locale.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "spanish");

    Cadena cad1("Hola, ");
    Cadena cad2("que ");
    Cadena cad3("tal ?");

    //Cadena saludo = " "+ cad3 + "?";
    Cadena saludo = '¡' + cad1 + "!, " + cad2 + " " + cad3 + 22 ;
    cout << saludo << endl;

   	filebuf fb;
	fb.open(argv[1], ios::in);

	if(!fb.is_open())
		throw "No se pudo abrir el archivo\n";

	istream lorem(&fb);


    filebuf fb2;
	fb2.open(argv[2], ios::out);

	if(!fb2.is_open())
		throw "No se pudo abrir el archivo\n";

    ostream lorem2(&fb2);

    Cadena linea;
	int nroLinea = 1;
	while(!lorem.eof())
	{
		lorem >> linea;

		if(nroLinea % 2 == 0)
			linea.aMayuscula();
		else
			linea.aMinuscula();

		lorem2 << linea << endl;

		nroLinea++;
	}

	fb.close();
    fb2.close();

    return 0;
}
