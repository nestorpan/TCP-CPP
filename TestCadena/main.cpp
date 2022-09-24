#include <iostream>
#include <fstream>
#include "../Cadena/Cadena.h"


using namespace std;


void funcionQueRecibeCopia(Cadena cCopia);


int main()
{
    system("chcp 1252 > nul");

    Cadena c1("Chau que mal");

    Cadena c4(c1);
    Cadena c5 = c4;
    Cadena c6 = "Hola mundo";
    Cadena c7;
    c7 = c1;
    // funcionQueRecibeCopia(c7);

//    cout << c3 << endl;
/*
    cout << "Ingrese una cadena:" << endl;
    cin >> c1 >> c4;
    cout << "La cadena ingresada es: " << c1 << c4 << endl;
*/
    // cout << "Ingrese una cadena (2):" << endl;
    // cin >> c1;
    // cout << "La cadena ingresada es: " << c1 << endl;

    fstream archivo("archivo.txt", ios::in);
    fstream archivoSal("archivoSal.txt", ios::out);

    /*
    archivo >> c1;
    cout << c1 << endl;
    archivoSal << c1 << endl;
    */

    while(!archivo.eof())
    {
        archivo >> c1;
        cout << c1 << endl;
        archivoSal << c1 << endl;
    }

    archivo.close();
    archivoSal.close();

    return 0;
}


void funcionQueRecibeCopia(Cadena cCopia)
{
//    cout << cCopia << endl;

    Cadena c2("Mundo");
    Cadena c3 = "Hola " + c2 + "!!!" + ' ' + 123;
    cout << c3 << endl;
}
