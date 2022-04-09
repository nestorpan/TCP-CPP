#include <iostream>
#include "../Fecha/Fecha.h"

using namespace std;


int main()
{
    Fecha fDefault;
    Fecha fecha1(1, 1, 2000);
    Fecha fecha2(25, 12, 2020);

    int dif = fecha1.difEnDias(&fecha2);
    int dif2 = fecha1 - &fecha2;

    Fecha fSuma = fecha1.sumarDias(60);
    Fecha fSuma2 = fecha1 + 60;

    Fecha fSuma3 = fDefault.sumarDias(60);
    Fecha fSuma4 = fDefault + 60;

    /*
    cout << "dif =  " << fSuma3.getDiaRel() << endl;
    cout << "dif2 = " << fSuma4.getDiaRel() << endl;
    */

    return 0;
}
