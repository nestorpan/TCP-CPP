#include <iostream>
#include <Fecha.h>
#include <FechaException.h>

using namespace std;


int main()
{
//	const Fecha f;


//	cout << "Fecha " << endl;

    try {
        Fecha f(29, 2, 2020);
    }
    catch(FechaException& ex) {
        // cout << "Se ha producido un error ==> " << ex.getMensaje() << endl;
        return -1;
    }

   const Fecha f2(31, 12, 2019);
   Fecha sum = f2.sumarDias(366);
   // Fecha sum = f2 + 30;

   int dia, mes, anio;
   sum.getDMA(dia, mes, anio);
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
   const Fecha fHoy(19, 9, 2019);
   const Fecha fAyer(18, 9, 2018);

   cout << "Resulatdo " << (fHoy.esMenor(fAyer)? "OK":"NO OK") << endl;

    return 0;
}
