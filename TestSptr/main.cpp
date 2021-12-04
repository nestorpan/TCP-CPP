#include <iostream>

#include "../SmartPointer/Sptr.h"
#include "../Fecha/Fecha.h"

using namespace std;


void imprimirFecha(const Fecha& fecha);
void operarConFechas();


int main()
{
    operarConFechas();

    return 0;
}


void imprimirFecha(const Fecha& fecha)
{
    cout << "La fecha es: " << fecha << endl;
}


void operarConFechas()
{
    Sptr<Fecha> fecha = new Fecha(1, 1, 2000);
    
    Sptr<Fecha> fecha2 = fecha;
    
    cout << *fecha2 << " + 30 días: " << *fecha2 + 30 << endl;
	
	int d = 4, m = 12, a = 2021;
	fecha2->setDMA(d, m, a);
	
    imprimirFecha(*fecha2);
}
