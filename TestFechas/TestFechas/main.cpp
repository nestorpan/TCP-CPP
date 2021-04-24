#include <iostream>
#include <fstream>
#include <iomanip>

#include "Fecha.h"
#include "FechaException.h"

#define ERR_INGR_FECHA 1
#define ARG_TXT_SAL 1

using namespace std;


int main(int argc, char* argv[])
{
	filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream salida(&fbSal);

    Fecha hoy;

    try {
        hoy = Fecha(24, 4, 2021);
    }
    catch(FechaException& fechaException) {
        //cout << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
        salida << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
		return ERR_INGR_FECHA;
    }

    Fecha pepito;
//    Fecha ayer = Fecha();

//    int diaAyer, mesAyer, anioAyer;
//    ayer.getDMA(&diaAyer, &mesAyer, &anioAyer);
//    cout << "La fecha ayer es: " << setw(2) << fixed << diaAyer << '/' << setw(2) << fixed << mesAyer << '/' << setw(4) << fixed << anioAyer << endl;


    //pepito = hoy.sumarDias(30);
    //hoy += 60;
//    pepito = 60 + hoy;
/*
    cout << ++hoy << endl; // 25/04
    cout << hoy++ << endl; // 25/04
    cout << hoy << endl;    // 26/04
*/
    //salida << hoy << endl;

    // hoy += 30;

    int dia, mes, anio;

    hoy.getDMA(&dia, &mes, &anio);

//    cout << "anio: " << anio << (Fecha::esBisiesto(2020)?"":" NO ")<< "es bisiesto" << endl;

 //   cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;


    hoy = Fecha::hoy();
    /*
	cout << hoy << endl;
	cout << hoy++ << endl;
	cout << ++hoy << endl;
*/
	// cout << 10 + hoy << endl;
	cout << "Mas 4 meses ==> " << hoy.sumarMeses(4) << endl;

/*
    Fecha maniana = hoy++;
    hoy.getDMA(&dia, &mes, &anio);
    cout << "hoy es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;

    //hoy++;
    maniana.getDMA(&dia, &mes, &anio);
    cout << "Ma�ana es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;

*/
    return 0;
}
