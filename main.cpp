#include <iostream>
#include <fstream>
#include "Fecha.h"
#include "Cadena.h"

using namespace std;


int main()
{
/**
    Fecha fDef;
    Fecha fIngr;
    
    cout << "Ingrese una fecha(d/m/a): " << endl;
    cin >> fIngr;
  
	
	filebuf fbIn;
	fbIn.open("in.txt", ios::in);
	istream in(&fbIn);
	
	in >> fIngr;
	
	fbIn.close();
	
    int d, m, a;
    
    fIngr.getDMA(d, m, a);
    
    cout << "La fecha es: " << fIngr << endl;
    
    Fecha fSuma = fIngr + 90;
	
	cout << "La fecha suma es: " << fSuma << endl;
	
	filebuf fb;
	fb.open("out.txt", ios::out);
	ostream out(&fb);
	
	out << "La fecha suma es: " << fSuma << endl;
	
	fb.close();
*/
/**	
	Cadena hola("Hola");
	Cadena holaCopy(hola);
	Cadena que("que");
	Cadena tal("tal");
	Cadena nombre("Pepe");
*/
/**	
	cout << "Ingrese su nombre: ";
	cin >> nombre;
*/
/**	
	Cadena saludo = hola + ' ' + nombre + "! " + que + ' ' + tal + '?';
	
	cout << saludo << endl;
*/
/**	
	Cadena linea;

	filebuf fbIn;
	fbIn.open("in.txt", ios::in);
	istream in(&fbIn);
	
	while(!in.eof())
	{
		in >> linea;
		cout << linea << endl;
	}
	
	fbIn.close();
*/
	
	PersonaBuilder builder;
	builder.setDni(11222333);
	builder.setNombres("Pepe Alberto");
	
	Persona pepe;
	
	try
	{
		pepe = builder.build();
	}
	catch(PersonaException& ex)
	{
		cout << "Error construyendo a la persona\n";
		return 1;
	}
	
	cout << pepe << endl;
	
    return 0;
}
