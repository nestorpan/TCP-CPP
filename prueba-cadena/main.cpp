#include <iostream>
#include <string>

#include <Cadena.h>

using namespace std;


int main()
{
	Cadena cad1("Hola");
	Cadena cad2("que");
	Cadena cad3("tal");
	
	Cadena frase = "¿" + cad1 + ", " + cad2 + ' ' + cad3 + '?' + ". Son las " + 10 + ':' + 22;
	
	cout << frase << endl;
	
	vector<Cadena> palabras = frase.split(' ');
	
	for(vector<Cadena>::iterator i = palabras.begin(); i < palabras.end(); i++)
		cout << *i << endl;
	
	
	
/**	
	string cad1("Hola");
	string cad2("que");
	string cad3("tal");
	
	string frase = "¿" + cad1 + ", " + cad2 + ' ' + cad3 + '?' + ". Son las " + 10 + ':' + 22;
	
	cout << frase << endl;
*/	
	return 0;
}
