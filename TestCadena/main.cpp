#include <iostream>
#include <fstream>

#include "../Cadena/Cadena.h"

using namespace std;


void func1();


int main(int argc, char* argv[])
{
///    func1();
    
    filebuf fb;
	fb.open(argv[1], ios::in);
	istream emplIS(&fb);
    
    Cadena linea;
    
    while(!emplIS.eof())
    {
        emplIS >> linea;
        cout << linea << endl;
    }
    
    fb.close();
    
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
