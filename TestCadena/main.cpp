#include <iostream>
#include <fstream>
#include "../Cadena/Cadena.h"


using namespace std;


int main()
{
    Cadena cadena1("Hola");
    Cadena cadena2("Mundo");

    Fecha fecha1(1, 1, 2020);

//    Cadena linea = cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha1;

    Cadena linea = "Este ejemplo " + cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha1;

    cout << linea << endl;

    fstream archivo("archivo.txt", ios::out);

    archivo << linea << endl;
    archivo << linea << endl;

    archivo.close();

    linea.normalizarInSitu();
    Cadena normalizada = linea.normalizar();


    //TODO: Hacer que funcione el ejemplo
    //TODO: Agregar + con float / double
    //TODO: Hacer +=, <, >, <= y >=, <<, >>
    //TODO: Normalizar


    return 0;
}
