#include <iostream>
#include <Cadena.h>

using namespace std;


int main()
{
	Cadena cad1("Hola ");
	Cadena cad2("que ");
	Cadena cad3("tal");
	
///	Cadena frase = cad1 + ", " + cad2 + ' ' + cad3 + '?';
	Cadena frase = cad1 + cad2 + cad3;
	
	cout << frase << endl;
	
	return 0;
}
