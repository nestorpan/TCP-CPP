#include <iostream>
#include <fstream>
#include <Fecha.h>
#include <FechaException.h>

using namespace std;

#define ARG_TXT_SAL 1
#define ERR_INGR_FECHA 1


int main(int argc, char* argv[])
{
	filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream salida(&fbSal);
	
	const Fecha f(12, 1, 2020);
	
	int dias = 30;
	Fecha sum = dias + f;

	cout << f << " + " << dias << " dias es: " << sum << endl;
	salida << f << " + " << dias << " dias es: " << sum << endl;
	
	Fecha f2(12, 1, 2021);
	
//	int dif = f2 - f;
	
	cout << "Dif en días: " << f2 - f << endl;
	salida << "Dif en días: " << f2 - f << endl;
	
	string sino;
	
	if(f >= f2)
		sino = "no";
	
	cout << f << sino << " es menor que " << f2 << endl;
	salida << f << sino << " es menor que " << f2 << endl;
	
	
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
