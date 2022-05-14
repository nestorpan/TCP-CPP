#include <iostream>
#include "../Cadena.h"


using namespace std;


int main()
{
    Cadena cadena1("Hola");
    Cadena cadena2("Mundo");

    Fecha fecha1(1, 1, 2020);

    Cadena linea = cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha;
    
    Cadena linea = "Este ejemplo " + cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha;
    
    cout << linea << endl;
    
    //TODO: Hacer que funcione el ejemplo
    //TODO: Agregar + con float / double
    //TODO: Hacer +=, <, >, <= y >=, <<, >>
    //TODO: Normalizar


    return 0;
}
