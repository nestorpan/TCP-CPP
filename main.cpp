#include <iostream>
#include <fstream>
#include "Alumno.h"
#include "Cuadrado.h"
#include "Circulo.h"
#include "Pentagono.h"

using namespace std;


void printFigura(const Figura& fig);
void printFiguras(Figura* vecFig[], int ce);


int main()
{
/**
    Fecha fDef;
    Fecha fIngr;
    
  ///  cout << "Ingrese una fecha(d/m/a): ";
    
  ///  cin >> fIngr;
	
    filebuf fbIn;
	fbIn.open("test.txt", ios::in);
	istream archivoIn(&fbIn);
	archivoIn >> fIngr;
	fbIn.close();
	
    
    int d, m, a;
    
    fIngr.getDMA(d, m, a);
    
    cout << "La fecha es " << d << '/' << m << '/' << a << endl;
    
    
    Fecha fSuma = fIngr + 90;
	
	fSuma.getDMA(d, m, a);
	
  ///  cout << "La fecha suma es " << d << '/' << m << '/' << a << endl;
    
    cout << "La fecha suma es " << fSuma << endl;
 */ 
 
 
 /**   
    filebuf fb;
	fb.open ("test.txt", ios::out);
	ostream archivo(&fb);
	archivo << "La fecha suma es " << fSuma << endl;
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
    Cadena hola2(hola);
    
    Cadena que("que");
    Cadena tal("tal");
    
    Cadena nombre("Pepe");
    
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
	fbIn.open("test.txt", ios::in);
	istream archivoIn(&fbIn);
	
	while(!archivoIn.eof())
	{
		archivoIn >> linea;
		cout << linea << endl;
	}
	
	fbIn.close();
*/	
/**	
	PersonaBuilder builder;
	builder.setDni(11222333);
	builder.setApellido("Perez");
	builder.setNombres("Pepe Alberto");
	
	Persona pepe = builder.build();
	
	cout << pepe.getApellido();
	
///	cout << pepe << endl;
*/
/**	
	AlumnoBuilder builder;
	builder.setDni(11222333);
	builder.setApellido("Perez");
	builder.setNombres("Juan Pedro");
	builder.setPromedio(7);
	builder.setCarrera("ING. INFORMATICA");
	
	Alumno juan = builder.build();
*/	
/**	
	filebuf fbIn;
	fbIn.open("Personas.txt", ios::in);
	istream personasIn(&fbIn);
	
	Persona pers;
	
	while(personasIn.peek() != EOF)
	{
		personasIn >> pers;
		cout << pers << endl;
	}
*/

/**
	AlumnoBuilder builder;
	builder.setDni(11222333);
	builder.setApellido("Perez");
	builder.setNombres("Juan Pedro");
	builder.setPromedio(7);
	builder.setCarrera("ING. INFORMATICA");
	
	Alumno juan = builder.build();
	
	cout << juan << endl;
*/	


/**
	filebuf fbIn;
	fbIn.open("Alumnos.txt", ios::in);
	istream alumnosIn(&fbIn);
	
	AlumnoBuilder aluBuilder;
	Alumno alu = aluBuilder.build();
	
	while(alumnosIn.peek() != EOF)
	{
		alumnosIn >> alu;
		cout << alu << endl;
	}
*/	
	
	Cuadrado cuad(10);
/**	
	cout << "Perimetro del cuadrado: " << cuad.perimetro() << endl;
	cout << "Area del cuadrado: " << cuad.area() << endl;
*/	
	
	printFigura(cuad);
	
	Circulo circ(10);
/**	
	cout << "Perimetro del circulo: " << circ.perimetro() << endl;
	cout << "Area del circulo: " << circ.area() << endl;
*/
	
	printFigura(circ);
	
	Pentagono penta(10);
	
	printFigura(penta);
	
	Figura* vecFig[3];
	
	vecFig[0] = &cuad;
	vecFig[1] = &circ;
	vecFig[2] = &penta;
	
	cout << "Vector de Figuras\n"; 
	printFiguras(vecFig, 3);
	
    return 0;
}


void printFigura(const Figura& fig)
{
	cout << "Perimetro del " << fig.nombre() << ": " << fig.perimetro() << endl;
	cout << "Area del " << fig.nombre() << ": " << fig.area() << endl;
}


void printFiguras(Figura* vecFig[], int ce)
{
	for(int i = 0; i < ce; i++)
		printFigura(*vecFig[i]);
}
