#include "../Cadena/Cadena.h"


void saludar();
void funcionX();


int main()
{
	saludar();
	
	funcionX();
	
    return 0;
}


void saludar()
{
    Cadena cad1("Hola");
    Cadena cad2("que");
    Cadena cad3("tal");
    
   Cadena saludo = "Constante " + cad1 + ", " + cad2 + ' ' + cad3 + '?' + 12;

   cout << saludo << endl;
}


void funcionX()
{
	cout << "Soy funcionX()" << endl;
}
