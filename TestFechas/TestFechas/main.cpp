#include <iostream>
#include <fstream>
#include <iomanip>

#include "Fecha.h"
#include "FechaException.h"

#define ERR_INGR_FECHA 1
#define ARG_TXT_SAL 1
#define ARG_TXT_ENT 2

using namespace std;


int main(int argc, char* argv[])
{
	filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream salida(&fbSal);
    
    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream entrada(&fbEnt);
    
        
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
    Fecha ayer = --Fecha::hoy();
    salida << "La fecha ayer es: " << ayer << endl;
    
    //pepito = hoy.sumarDias(30);
    hoy += 60;
//    pepito = 60 + hoy;
    
    cout << ++hoy << endl; // 25/04
    cout << hoy++ << endl; // 25/04
    cout << hoy << endl;    // 26/04
    
    salida << "La fecha hoy es: " << hoy << endl;
    
    // hoy += 30;

    int dia, mes, anio;
    
    hoy.getDMA(dia, mes, anio);
    
//    cout << "anio: " << anio << (Fecha::esBisiesto(2020)?"":" NO ")<< "es bisiesto" << endl;

 //   cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;


    hoy = Fecha::hoy();
    
    salida << "Hoy posta es: " << hoy << endl;
    
    /*
	cout << hoy << endl;
	cout << hoy++ << endl;
	cout << ++hoy << endl;
*/
	// cout << 10 + hoy << endl;
	salida << "Mas 4 meses ==> " << hoy.sumarMeses(4) << endl;

    Fecha maniana = ++hoy;
    salida << "Mañana es: " << maniana << endl;
    
    Fecha fIngresada;
    
    while(entrada.peek() != EOF)
    {
        entrada >> fIngresada;
        entrada.ignore(1);
        cout << "La fecha ingresada del archivo es: " << fIngresada << endl;
    }
    
    
    return 0;
}
