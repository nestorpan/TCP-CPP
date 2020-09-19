#include <iostream>
#include <Fecha.h>

using namespace std;


int main()
{
	const Fecha f(29, 1, 2020);
	
	Fecha sum = f.sumarDias(31);
	Fecha sum = f + 30;
	
	int dia, mes, anio;
	
	sum.getDMA(dia, mes, anio);
	
	cout << "La suma es: " << dia << '/' << mes << '/' << anio << endl;
	
	Fecha f2(12, 9, 2020);
	
///	int dif = f.difEnDias(f2);
 int dif = f - f2; ///Sobrecarga de operadores
	
    return 0;
}
