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
    
    Cadena hola("Hola");
    Cadena hola2(hola);
    
    Cadena que("que");
    Cadena tal("tal");
    
    Cadena nombre("Pepe");
 /**   
    cout << "Ingrese su nombre: ";
    cin >> nombre;
 */   
    Cadena saludo = hola + ' ' + nombre + "! " + que + ' ' + tal + '?';
    
    cout << saludo << endl;
    
    return 0;
}
