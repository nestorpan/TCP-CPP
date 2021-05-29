#include <iostream>
#include <fstream>
#include <iomanip>

#include "../Cadena/Cadena.h"

using namespace std;


void func1();


int main(int argc, char* argv[])
{
//    func1();
    
    filebuf fb;
	fb.open(argv[1], ios::in);
	istream emplIS(&fb);
    
    Cadena linea;
    
    while(!emplIS.eof())
    {
        emplIS >> linea;
        vector<Cadena> campos = linea.split('|');
        
        for(vector<Cadena>::iterator i = campos.begin(); i < campos.end(); i++)
            cout << setw(20) << *i << "\t";
        
        cout << endl;
    }
    
    fb.close();
    
    return 0;
}


void func1()
{
    Cadena c1("Hola"), c2("qué"), c3("tal"), c4(c1);
    
///    c1 = c2 = c3 = c4;
    
    Cadena saludo("¡");
    saludo += c1 + "!, " + c2 + ' ' + c3 + "? - " + 15;
    
    Cadena saludo2 = "¡¡" + c1 + "!!";
    
    Cadena saludo3 = saludo2;
    
    cout << saludo << endl;
    cout << saludo2 << endl;
}
