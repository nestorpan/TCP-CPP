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
    
    int d, m, a;
    char c;
    
    cout << "Ingrese una fecha (D/M/A): --> ";
    cin >> d >> c >> m >> c >> a;
    
    try
    {
        Fecha hoy(d, m, a);
        
        hoy.getDMA(d, m, a);
    
        cout << d << '/' << m << '/' << a << endl;
        
        Fecha hoyCopia(hoy);
        
        hoy.getDMA(d, m, a);
        
        cout << d << '/' << m << '/' << a << endl;
        
        int dias = -200000;
        
        Fecha ayer;
        ayer = hoy;
        
        Fecha ayer(hoy);
        Fecha ayer = hoy;
        
//        cout << "La fecha + 60 es: " << hoy += dias << ayer = hoy += dias << endl;
        
        hoy.getDMA(d, m, a);
        
        cout << "hoy + dias:" << endl;
        cout << d << '/' << m << '/' << a << endl;
        
        Fecha suma = hoy + dias;
        
        suma.getDMA(d, m, a);
        
        cout << "suma:" << endl;
        cout << d << '/' << m << '/' << a << endl;
        
        int dif = suma - hoy;
        
        cout << "La dif entre suma y hoy es: " << dif << endl;
    }
    catch(FechaInvalidaException ex)
    {
        cout << ex.getMensaje() << endl;
        return ERR_FECHA_INV;
    }
    
    return TODO_OK;
}
