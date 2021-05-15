#include <iostream>

#include "../Cadena/Cadena.h"

using namespace std;


void func1();


int main()
{
    func1();
    
    ///...
    
    return 0;
}


void func1()
{
    Cadena c1("Hola"), c2("que"), c3("tal");
    
    Cadena saludo = c1 + ", " + c2 + ' ' + c3 + "? - " + 15;
    
    Cadena saludo2 = "¡¡" + c1 + "!!";
    
    cout << saludo << endl;
    cout << saludo2 << endl;
}
