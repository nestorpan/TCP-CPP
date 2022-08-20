#include <iostream>
#include "../Fecha/Fecha.h"

using namespace std;


int main()
{
    Fecha fDefault;
    Fecha f(20, 8, 2022);

    Fecha fSuma = f.sumarDias(180);

    int difDias = f.diferenciaEnDias(fSuma);

    cout << "Diferencia de dias: " << difDias << endl;
    
    return 0;
}
