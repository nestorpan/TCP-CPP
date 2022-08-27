#include <iostream>
#include "../Fecha/Fecha.h"
#include <locale.h>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");

    Fecha fDefault;
    const Fecha f(29, 2, 2020);

    Fecha fSuma = f.sumarDias(180);

    int difDias = f.diferenciaEnDias(fSuma);

    cout << "Diferencia de dias: " << difDias << endl;

 //   Fecha fDefSuma = fDefault.sumarDias(200);

    // mostrar f
    int dia, mes, anio;
    fSuma.getDma(&dia, &mes, &anio);

    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;

    //cout << "Fecha: " << fSuma << endl;

    return 0;
}
