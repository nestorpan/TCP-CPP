#include <iostream>
#include "Figura.h"

using namespace std;


Figura::Figura(const string& nombre)
: nombre(nombre)
{}


Figura::~Figura()
{
    cout << "Destruyendo figura " << nombre << endl;
}


const string& Figura::getNombre() const
{
    return nombre;
}
