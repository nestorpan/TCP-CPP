#include "Figura.h"


Figura::Figura(string nombre)
: nombre(nombre)
{

}


const string& Figura::getNombre() const
{
	return nombre;
}
