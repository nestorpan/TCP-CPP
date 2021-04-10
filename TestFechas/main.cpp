#include <iostream>
#include "Fecha.h"

using namespace std;

int main()
{
    Fecha hoy(10, 4, 2021);
  //  Fecha ayer = Fecha(11, 4, 2021);
   // Fecha* manana = new Fecha(10, 4, 2021);

    Fecha defaulteada;
    //defaulteada.setDiaRel(25);
    cout << "defaulteada diaRel ==> " << defaulteada.getDiaRel();
//    defaulteada.diaRel;

    hoy = hoy.sumarDias(30);

    //hoy.diaRel = 45;

    return 0;
}
