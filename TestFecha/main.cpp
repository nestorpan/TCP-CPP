#include <iostream>
#include "../Fecha/Fecha.h"

using namespace std;

int main()
{
    Fecha hoy(4, 9, 2021);

//    Fecha mas30 = hoy.sumarDias(30);

    int d, m, a;
    hoy.getDMA(&d, &m, &a);

	cout << d << '/' << m << '/' << a << endl;


    Fecha hoyCopia(hoy);

    hoyCopia.getDMA(&d, &m, &a);

	cout << d << '/' << m << '/' << a << endl;

    cout << "Fecha "<< (Fecha::esFechaValida(29, 2, 2021)?"":"NO " ) <<"OK!!" << endl;

    cout << "Fecha "<< (hoyCopia.esFechaValida(29, 2, 2021)?"":"NO " ) <<"OK!!" << endl;
    return 0;
}
