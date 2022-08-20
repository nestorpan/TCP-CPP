#include <iostream>
#include "../Fecha/Fecha.h"
#include <locale.h>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");

    Fecha fDefault;
    Fecha f(20, 8, 2022);

    Fecha fSuma = f.sumarDias(180);

    int difDias = f.diferenciaEnDias(fSuma);

    cout << "Diferencia de dias: " << difDias << endl;

    cout << "Día de la semana: " << f.diaDeLaSemanaStr() << endl;

    //cout << "vectorDiaSemana: " << Fecha::vectorDiaSemana[6] << endl;

    return 0;
}
