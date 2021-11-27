#include <iostream>

#include "../Fecha/Fecha.h"
#include "../Comun/OrdenarConPilas.h"

using namespace std;


int main()
{
	int ce = 10;
	int vector[ce] = {10, 2, 9, 7, 3, 8, 1, 4, 5, 6};
	
	Fecha vectorFechas[ce] =
	{
		Fecha(10, 10, 2010),
		Fecha(2, 2, 2002),
		Fecha(9, 9, 2009),
		Fecha(7, 7, 2007),
		Fecha(3, 3, 2003),
		Fecha(8, 8, 2008),
		Fecha(1, 1, 2001),
		Fecha(4, 4, 2004),
		Fecha(5, 5, 2005),
		Fecha(6, 6, 2006)
	};

	ordenarConPilas<int>(vector, ce);

	for (int i = 0; i < ce; i++)
		cout << vector[i] << " ";

	cout << endl;

	
	ordenarConPilas<Fecha>(vectorFechas, ce);

	for (int i = 0; i < ce; i++)
		cout << vectorFechas[i] << " ";

	cout << endl;

	return 0;
}
