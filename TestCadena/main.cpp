#include <vector>
#include <fstream>

#include "../Cadena/Cadena.h"


void saludar();
void funcionX();


int main(int argc, char* argv[])
{
	saludar();
/*	
	funcionX();
	
	Cadena cadIngresada;
	
	cout << "Ingresá un texto (Al finalizar dale enter).\n-->";
	cin >> cadIngresada;
	
	cout << "Cadena ingresada: " << cadIngresada << endl;
*/	
	
	filebuf fb;
	fb.open(argvv[1], ios::in);
	
	if(!fb.is_open())
		throw "No se pudo abrir el archivo\n";
	
	istream lorem(&fb);
	
	filebuf fb2;
	fb2.open(argvv[2], ios::out);
	
	if(!fb2.is_open())
		throw "No se pudo abrir el archivo\n";
	
	ostream lorem2(&fb2);
	
	Cadena linea;
	int nroLinea = 1;
	while(!lorem.eof())
	{
		lorem >> linea;
		
		if(nroLinea % 2 == 0)
			linea.aMayuscula();
		else
			linea.aMinuscula();
		
		lorem2 << linea << endl;
		
		nroLinea++;
	}
	
	fb.close();
	fb2.close();
	
    return 0;
}


void saludar()
{
    Cadena cad1("Hola");
    Cadena cad2("que");
    Cadena cad3("tal");
    
   	Cadena saludo = "Constante " + cad1 + ", " + cad2 + ' ' + cad3 + '?' + 12;
	
   	cout << saludo << endl;
   
	Cadena cadCopia(cad1);
   	
   	cout << "La copia es: " << cadCopia << endl;
   	
   	Cadena cad4 = cad1 = cad2 = cad3 = "Hola";
}


void funcionX()
{
	cout << "Soy funcionX()" << endl;
}
