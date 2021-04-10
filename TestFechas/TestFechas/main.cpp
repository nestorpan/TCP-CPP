#include <iostream>

#include "Fecha.h"


using namespace std;


int main()
{
    Fecha hoy(10, 4, 2021);
    Fecha defaulteada;
    
    hoy = hoy.sumarDias(30);
    
    hoy.diaRel = 45;
    
    return 0;
}
