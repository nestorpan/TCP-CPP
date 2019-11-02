#include <iostream>
#include <fstream>
#include "Fecha.h"
#include "Cadena.h"
#include "Persona.h"
#include "PersonaException.h"
#include "Alumno.h"


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
	
	
	Fecha hoy(2, 11, 2019);
	Fecha maniana = hoy++;
	Fecha pasado = ++hoy;
	
	cout << "hoy: " << hoy << endl;
	cout << "maniana: " << maniana << endl;
	cout << "pasado: " << pasado << endl;
	
	
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
/**	
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
		cout << Cadena("Error construyendo a la persona: ") + ex.getMensaje() << endl;
		return 1;
	}
	
///	cout << pepe << endl;
	
*/
/**	
	AlumnoBuilder builder;
	
	builder.setDni(-4);
	builder.setMatricula(12345);
	builder.setApellido("Perez");
	builder.setNombres("Juan Ignacio");
	builder.setFechaIngr(Fecha(26, 10, 2019));
	
	Alumno alu;
	
	try
	{
		alu = builder.build();
	}
	catch(Exception& ex)
	{
		cout << Cadena("Error creando el alumno: ") + ex.getMensaje() << endl;
	}
*/

/**	
	filebuf fbIn;
	fbIn.open("Personas.txt", ios::in);
	istream in(&fbIn);
	
	Persona persona;
	
	while(in.peek() != EOF)
	{
		in >> persona;
		cout << persona << endl;
	}
	
	fbIn.close();
*/
/**	
	AlumnoBuilder builder;
	
	builder.setDni(11222333);
	builder.setApellido("Perez");
	builder.setNombres("Juan Ignacio");
	builder.setMatricula(12345);
	builder.setFechaIngr(Fecha(26, 10, 2019));
	
	Alumno alu;
	
	try
	{
		alu = builder.build();
	}
	catch(Exception& ex)
	{
		cout << Cadena("Error creando el alumno: ") + ex.getMensaje() << endl;
	}
	
	cout << alu << endl;
*/	
	
/**	
	filebuf fbIn;
	fbIn.open("Alumnos.txt", ios::in);
	istream in(&fbIn);
	
	Alumno alumno;
	
	while(in.peek() != EOF)
	{
		in >> alumno;
		cout << alumno << endl;
	}
	
	fbIn.close();
*/
	
    return 0;
}
