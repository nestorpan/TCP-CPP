#include <iostream>
#include "Fecha.h"

using namespace std;


int main()
{
    Fecha fDef;
    Fecha fHoy(31, 8, 2019);
    
    int d, m, a;
    
    fHoy.getDMA(d, m, a);
    
    cout << "La fecha es: " << d << '/' << m << '/' << a << endl;
    
    Fecha fSuma = fHoy + 90;
    
	fSuma.getDMA(d, m, a);
    
    cout << "La fecha suma es: " << d << '/' << m << '/' << a << endl;
	
    return 0;
}
