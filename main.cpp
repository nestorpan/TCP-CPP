#include <iostream>
#include <fstream>
#include "Fecha.h"

using namespace std;


int main()
{
    Fecha fDef;
    Fecha fIngr;
 /*   
    cout << "Ingrese una fecha(d/m/a): " << endl;
    cin >> fIngr;
 */ 
	
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
	
    return 0;
}
