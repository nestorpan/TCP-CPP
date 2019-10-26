#include <iostream>
#include <fstream>
#include "Alumno.h"


using namespace std;


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
    
    
    filebuf fb;
	fb.open ("test.txt", ios::out);
	ostream archivo(&fb);
	archivo << "La fecha suma es " << fSuma << endl;
	fb.close();
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
	
	while(!personasIn.eof())
	{
		personasIn >> pers;
		cout << pers << endl;
	}
*/
	
    return 0;
}
