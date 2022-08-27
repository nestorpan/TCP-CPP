#include <iostream>
#include "../Fecha/Fecha.h"

using namespace std;


int main()
{
    Fecha fDefault;
    const Fecha f(20, 8, 2022);

    Fecha fSuma = f.sumarDias(180);

    int difDias = f.diferenciaEnDias(fSuma);

    cout << "Diferencia de dias: " << difDias << endl;

 //   Fecha fDefSuma = fDefault.sumarDias(200);

    // mostrar f
    int dia, mes, anio;
    fSuma.getDma(&dia, &mes, &anio);

    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;

    return 0;
}
