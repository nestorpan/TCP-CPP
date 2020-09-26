#include <iostream>
#include <Fecha.h>
#include <FechaException.h>
#include <fstream>

using namespace std;

#define ARG_TXT_SAL 1
#define ERR_INGR_FECHA 1

int main(int argc, char* argv[])
{
//	const Fecha f;

/*
	cout << "argc " << argc <<endl;
	cout << "argv[0] " << argv[0] <<endl;
	cout << "argv[1] " << argv[ARG_TXT_SAL] <<endl;
*/
    try {
        Fecha f(29, 2, 2020);
    }
    catch(FechaException& ex) {
        // cout << "Se ha producido un error ==> " << ex.getMensaje() << endl;
        return -1;
    }

   Fecha f2(31, 12, 2019);
///   Fecha sum = f2.sumarDias(366);
   Fecha sum = f2 + 30;
   sum+= 30;

   int dia, mes, anio;
   sum.getDMA(dia, mes, anio);

   cout << "La Fecha + 60 dias es ==> " << dia << "/" << mes << "/" << anio << endl;
/*
   if (dia == 31 && mes == 12 && anio == 2020) {
    cout << "La Fecha esparada OK!!!! "<< endl;
   }
   else {
    cout << "La Fecha esparada NO OK!!!! "<< endl;
   }

   cout << "La Fecha + 30 dias es ==> " << dia << "/" << mes << "/" << anio << endl;
*/

   /// Comparación de fechas
///   const Fecha fHoy(19, 9, 2019);
///   const Fecha fAyer(18, 9, 2018);

///   cout << "Resulatdo " << (fHoy.esMenor(fAyer)? "OK":"NO OK") << endl;

    Fecha f3(31, 12, 2019);
    Fecha f4(31, 12, 2020);
	//int dif = f3 - f4;

///	cout << "Dif en días: " << f3 - f4 << endl;

	string sino = " no";

	if(f3 < f4) {
        sino = "";
	}

///	cout << f3 << sino << " es menor que " << f4 << endl;

    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream salida(&fbSal);

	Fecha f5 = 30 + f4;
	cout << "f5 = 30 + f4 ==> " << f5 << endl;
	salida << "f5 = 30 + f4 ==> " << f5 << endl;

	Fecha fIngr;
	cout << "Ingrese una fecha (d/m/a):" << endl;

	try
	{
		cin >> fIngr;
	}
	catch(FechaException& ex)
	{
		cout << "Hubo un error en el ingreso de la fecha: " << ex.getMensaje() << endl;
		return ERR_INGR_FECHA;
	}

	cout << "La fecha ingresada es: " << fIngr << endl;



    return 0;
}
