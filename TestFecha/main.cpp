#include <iostream>

#include "../Fecha/Fecha.h"

using namespace std;


int main()
{
    Fecha hoy(29, 2, 2020);
    
//    Fecha mas30 = hoy.sumarDias(30);
    
    int d, m, a;
    hoy.getDMA(&d, &m, &a);
    
	cout << d << '/' << m << '/' << a << endl;
    
    Fecha hoyCopia(hoy);
    
    hoy.getDMA(&d, &m, &a);
    
	cout << d << '/' << m << '/' << a << endl;
    
        
    return 0;
}
