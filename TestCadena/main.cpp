#include <iostream>
#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"


using namespace std;


int main()
{
    Cadena cadena1("Hola");
    Cadena cadena2("Mundo");

    Fecha fecha(1, 1, 2020);

    Cadena linea = cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha;

    linea = "Este ejemplo " + cadena1 + ' ' + cadena2 + '!' + ' ' + 23 + ' ' + fecha;

    //cout << linea << endl;

    //TODO: Hacer que funcione el ejemplo
    //TODO: Agregar + con float / double
    //TODO: Hacer +=, <, >, <= y >=, <<, >>
    //TODO: Normalizar
    //TODO: split (trozar por un caracte, ej. "hola|mundo" ==> array[2]: split('|') ==> array[0]:"hola"; array[1]:"mundo")


    return 0;
}
