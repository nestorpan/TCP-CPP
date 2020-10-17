#include <iostream>
#include <string>
#include <fstream>

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
	
	filebuf fb;
	fb.open("empleados.txt", ios::in);
	istream emplIS(&fb);
	
	int cantLineas = 0;
	Cadena emplLinea;
	
	while(!(emplIS >> emplLinea).eof())
	{
		cout << emplLinea << endl;
		cantLineas++;
	}
	
	cout << Cadena("Habia ") + cantLineas + " lineas en el archivo." << endl;
	
	return 0;
}
