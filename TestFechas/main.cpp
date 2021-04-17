#include <iostream>
#include <iomanip>

#include "Fecha.h"


using namespace std;


int main()
{
    /*
	Fecha diaDelProg(13, 9, 2021);
    cout << "El dia relativo es: " <<  diaDelProg.getDiaRel() << endl;
*/


	Fecha hoy(17, 2, 2021);
	Fecha ayer(16, 2, 2021);

	cout << "la diferencia en dias es " << hoy.diferenciaEnDias(ayer) << endl;

    Fecha pepito;

    pepito = hoy.sumarDias(30);

    int dia, mes, anio;
    pepito.getDMA(&dia, &mes, &anio);


   	Fecha unaFecha(1, 1, 2021);

    int dia2, mes2, anio2;
    unaFecha.getDMA(&dia2, &mes2, &anio2);

    cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;
    cout << "La fecha suma es: " << setw(2) << fixed << dia2 << '/' << setw(2) << fixed << mes2 << '/' << setw(4) << fixed << anio2 << endl;


    cout << "La fecha suma es: " << dia << '/' << mes << '/' << anio << endl;
    cout << "La fecha suma es: " << dia2 << '/' << mes2 << '/' << anio2 << endl;

    return 0;
}
