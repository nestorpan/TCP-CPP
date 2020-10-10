#include <iostream>
#include <Cadena.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Cadena cad1("Hola");
	Cadena cad2("que");
	Cadena cad3("tal");

	char qs = 168;
	Cadena frase = qs + cad1 + ", " + cad2 + ' ' + cad3 + "!?" + ". Son las " + -14 + ':' + 10;

	cout << frase << endl;

	vector<Cadena> palabras = frase.split(' ');

	for(vector<Cadena>::iterator it = palabras.begin(); it < palabras.end(); it++) {
        cout << *it << endl;
	}

    /// String

	string cad11("Hola");
	string cad12("que");
	string cad13("tal");

	string frase2 = qs + cad11 + ", " + cad12 + ' ' + cad13 + "!?" + ". Son las ";

	cout << frase2 << endl;


    return 0;
}
