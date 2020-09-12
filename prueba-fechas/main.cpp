#include <iostream>
#include <Fecha.h>

using namespace std;


int main()
{
	const Fecha f(12, 9, 2020);
	
	Fecha sum = f.sumarDias(30);
///	Fecha sum = f + 30;
	
	int d, m, a;
	
	sum.getDMA(d, m, a);
	
	cout << "La suma es :" << d << '/' << m << '/' << a << endl;
	
	Fecha f2(12, 9, 2020);
	
///	int dif = f.difEnDias(f2);
/// int dif = f - f2; ///Sobrecarga de operadores
	
    return 0;
}
