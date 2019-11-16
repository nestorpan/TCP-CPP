#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Fecha.h"
#include "Cadena.h"
#include "Persona.h"
#include "PersonaException.h"
#include "Alumno.h"
#include "Figura.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Pentagono.h"
#include "Intercambiar.h"

using namespace std;

void printFigura(const Figura& figura);
void printFiguras(Figura* vecFig[], int ce);


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
	Fecha hoy(2, 11, 2019);
	Fecha maniana = hoy++;
	Fecha pasado = ++hoy;
	
	cout << "hoy: " << hoy << endl;
	cout << "maniana: " << maniana << endl;
	cout << "pasado: " << pasado << endl;
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
	
///	Cuadrado cuadrado(10);
/**	
	cout << "El perimetro del Cuadrado es: " << cuadrado.perimetro() << endl;
	cout << "El area del Cuadrado es: " << cuadrado.area() << endl;
*/	
///	Circulo circulo(10);
/**	
	cout << "El perimetro del Circulo es: " << circulo.perimetro() << endl;
	cout << "El area del circulo es: " << circulo.area() << endl;
*/	
/**	
	printFigura(cuadrado);
	
	printFigura(circulo);
	
	Pentagono pentagono(10);
	
	printFigura(pentagono);
	
	Figura* vecFig[3];
	
	vecFig[0] = &cuadrado;
	vecFig[1] = &circulo;
	vecFig[2] = &pentagono;
	
	cout << "Vector de Figuras:" << endl;
	printFiguras(vecFig, 3);
*/
/**	
	int a = 5, b = 8;
	
	intercambiar(a, b);
	
	cout << "a: " << a << ", b: " << b << endl;
*/
/**	
	Cadena hola("Hola");
	Cadena chau("Chau");
	
	intercambiar(hola, chau);
	
	cout << "hola: " << hola << ", chau: " << chau << endl;
*/

/**
	AlumnoBuilder builder;
	
	builder.setDni(11222333);
	builder.setApellido("Perez");
	builder.setNombres("Juan Ignacio");
	builder.setMatricula(12345);
	builder.setFechaIngr(Fecha(26, 10, 2019));
	
	Alumno juan;
	
	try
	{
		juan = builder.build();
	}
	catch(Exception& ex)
	{
		cout << Cadena("Error creando el alumno: ") + ex.getMensaje() << endl;
		return 1;
	}
	
	builder.setDni(22333444);
	builder.setApellido("Gutierrez");
	builder.setNombres("Pedro Dario");
	builder.setMatricula(54321);
	builder.setFechaIngr(Fecha(12, 1, 2008));
	
	Alumno pedro;
	
	try
	{
		pedro = builder.build();
	}
	catch(Exception& ex)
	{
		cout << Cadena("Error creando el alumno: ") + ex.getMensaje() << endl;
		return 1;
	}
	
	intercambiar(pedro, juan);
	
	cout << "juan: " << juan << endl;
	cout << "pedro: " << pedro << endl;
*/	
	
	filebuf fbIn;
	fbIn.open("Alumnos.txt", ios::in);
	istream in(&fbIn);
	
	vector<Alumno> vecAlumnos;
	list<Alumno> listaAlumnos;
	
	Alumno alumno;
	
	while(in.peek() != EOF)
	{
		in >> alumno;
	///	vecAlumnos.push_back(alumno);
		listaAlumnos.push_back(alumno);
	}
	
	fbIn.close();
/**	
	for(unsigned i = 0; i < vecAlumnos.size(); i++)
		cout << vecAlumnos[i] << endl;
*/	
/**	
	vector<Alumno>::iterator ult = vecAlumnos.end() - 1;
	vector<Alumno>::iterator ini = vecAlumnos.begin();
	
	for(vector<Alumno>::iterator it = ult; it >= ini; it--)
		cout << *it << endl;
*/
	
	listaAlumnos.sort(Persona::esMenorQuePorApellidoYNombres);
	
	for(list<Alumno>::iterator it = listaAlumnos.begin(); it != listaAlumnos.end(); it++)
		cout << *it << endl;
	
	
	
    return 0;
}


void printFigura(const Figura& figura)
{
	cout << "El perimetro del " << figura.nombre() << " es: " << figura.perimetro() << endl;
	cout << "El area del " << figura.nombre() << " es: " << figura.area() << endl;
	cout << "El apotema del " << figura.nombre() << " es: " << figura.apotema() << endl;
}


void printFiguras(Figura* vecFig[], int ce)
{
	for(int i = 0; i < ce; i++)
		printFigura(*vecFig[i]);
}


