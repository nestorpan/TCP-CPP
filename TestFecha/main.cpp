#include <iostream>
#include <locale.h>

#include "../Fecha/Fecha.h"
#include "../Fecha/FechaInvalidaException.h"

using namespace std;


#define TODO_OK 0;
#define ERR_FECHA_INV 1


int main()
{
    setlocale(LC_CTYPE, "spanish");
    
    try
    {
        Fecha hoy;
		
        cout << "Ingrese una fecha (D/M/A): --> ";
	    cin >> hoy;
		
        cout << "Fecha ingresada: " << hoy << endl;
        
        Fecha hoyCopia(hoy);
        
        cout << "Copia de la fecha ingresda: " << hoyCopia << endl;
        
        int dias = 60;
        
        Fecha ayer;
        ayer = hoy;
        
     //   Fecha ayer(hoy);
     //   Fecha ayer = hoy;
        
//        cout << "La fecha + 60 es: " << hoy += dias << ayer = hoy += dias << endl;
        
        cout << "hoy + dias: " << hoy << endl;
        
     //   Fecha suma = hoy + dias;
        Fecha suma = dias + hoy;
        
        cout << "suma:" << suma << endl;
        
        int dif = suma - hoy;
        
        cout << "La dif entre suma y hoy es: " << dif << endl;

                
        Fecha fa, fb, fx(18, 9, 2021);
        fa = fx++;
        fb = ++fx;

        cout << "fa: " << fa << endl;        
        cout << "fb: " << fb << endl;        
        cout << "fx: " << fx << endl;
    }
    catch(FechaInvalidaException ex)
    {
        cout << ex.getMensaje() << endl;
        return ERR_FECHA_INV;
    }

/*	
	int a, b, x = 5;
	a = x++; /// Posincremento
	b = ++x; /// Preincremento
	
    cout << "a: " << a << endl << "b: " << b << endl << "x: " << x << endl;
*/	
	
	
    return TODO_OK;
}
