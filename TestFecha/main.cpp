#include <iostream>
#include "../Fecha/Fecha.h"
#include <locale.h>


using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");
    Fecha fDefault;

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

    if (!Fecha::esFechaValida(1, 1, 2020)) cout << "OK!!!" << endl;


    Fecha diaDelProgramador(13, 9, 2022);

    /*
    int a=0, b=1;
    a = ++b; // a = 2 ; b = 2
    a = b++; // a = 1 ; b = 2
    */

    // fecha1 = fecha1 + 100;

    int dif = fecha1 - diaDelProgramador;

    cout << "Diferencia en dias (Debe ser -255): " << dif << endl;

    Fecha fSuma2 = fecha1 + 60;
    cout << "fSuma2: " << fSuma2 << endl;

    fecha1.setDMA(1, 8, 2020);
    int dia, mes, anio;
    fecha1.getDMA(dia, mes, anio);
    cout << "fecha1 es: " << dia << '/' << mes << '/' << anio << endl << endl;


    cout << "El día del programador es: " << diaDelProgramador << endl;

    cout << "Posincremento (13/9/2022): " << diaDelProgramador++ << endl;
    cout << "Preincremento (15/9/2022): " << ++diaDelProgramador << endl;

    return 0;
}
