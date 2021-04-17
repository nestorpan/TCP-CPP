#include <iostream>
#include <iomanip>

#include "Fecha.h"


using namespace std;


int main()
{
	Fecha hoy(17, 4, 2021);
    Fecha pepito;
    
    pepito = hoy.sumarDias(30);
    
    int dia, mes, anio;
    
    pepito.getDMA(&dia, &mes, &anio);
    
    cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;
    
    return 0;
}
