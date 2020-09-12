#include <iostream>
#include <Fecha.h>
#include <FechaException.h>

using namespace std;


int main()
{
//	const Fecha f;

//	Fecha sum = f.sumarDias(30);

//	cout << "Fecha " << endl;

    try {
        Fecha f(29, 2, 2021);
    }
    catch(FechaException& ex) {
        cout << "Se ha producido un error ==> " << ex.getMensaje() << endl;
        return -1;
    }

   cout << "Fecha OK" << endl;

    return 0;
}
