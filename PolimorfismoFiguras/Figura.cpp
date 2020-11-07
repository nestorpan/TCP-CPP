#include "Figura.h"


Figura::Figura(const Cadena& nombre, char genero)
: nombre(nombre), genero(genero)
{}


char Figura::getGenero() const
{
	return this->genero;
}


Cadena Figura::getNombre() const
{
	return this->nombre;
}
