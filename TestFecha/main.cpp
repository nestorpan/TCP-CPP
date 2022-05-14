#include <iostream>
#include <locale.h>
#include <windows.h>
#include "../Fecha/Fecha.h"

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");

    Fecha fecha1;
    bool esFechaValida = false;

    do
    {
        try
        {
            cout << "Ingrese una fecha (dd/mm/aaaa): ";
            cin >> fecha1;
//          fecha1 = Fecha(1, 1, 2022);
            esFechaValida = true;
        }
        catch(const FechaExc& ex)
        {
            cout << ex.getMensaje() << endl;
        }
    }
    while(!esFechaValida);


    Fecha diaDelProgramador(13, 9, 2022);

    int dif = fecha1 - diaDelProgramador;

    cout << "Diferencia en dias (Debe ser -255): " << dif << endl;

    Fecha fSuma2 = fecha1 + 60;

    fecha1.setDMA(1, 8, 2022);

    cout << "El día del programador es: " << diaDelProgramador << endl;

    cout << "Posincremento (13/9/2022): " << diaDelProgramador++ << endl;
    cout << "Preincremento (15/9/2022): " << ++diaDelProgramador << endl;

    return 0;
}
