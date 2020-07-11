#include <iostream>
#include "Figura.h"


Figura::Figura(string nombre)
: nombre(nombre)
{

}

/*
Figura::~Figura()
{
	cout << "Destruyendo Figura " << this->nombre << endl;
}
*/

const string& Figura::getNombre() const
{
	return nombre;
}
