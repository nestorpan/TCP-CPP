#include <iostream>
#include "../Cadena/Cadena.h"


using namespace std;


void funcionQueRecibeCopia(Cadena cCopia);


int main()
{
    Cadena c1("Hola");
 
    Cadena c4(c1);
    Cadena c5 = "Hola mundo";
    Cadena c6;
    c6 = c1;
    funcionQueRecibeCopia(c6);

//    cout << c3 << endl;

    return 0;
}


void funcionQueRecibeCopia(Cadena cCopia)
{
    cout << cCopia << endl;
    
    Cadena c2("Mundo");
//    Cadena c3 = "Hola" + cCopia + ' ' + c2 + "!!!" + ' ' + 123;
    Cadena c3;
    c3 = cCopia + c2;
    cout << c3 << endl;
}
