#include <string.h>
#include "Cadena.h"


Cadena::Cadena()
{
	cad = new char[1];
	*cad = '\0';
}


Cadena::Cadena(const char* cad)
{
	this->cad = new char[strlen(cad) + 1];
	strcpy(this->cad, cad);
}


Cadena::Cadena(const Cadena& other)
{
	this->cad = new char[strlen(other.cad) + 1];
	strcpy(this->cad, other.cad);
}


Cadena::~Cadena()
{
	cout << "Ejecutando destructor ..." << endl;
	delete [] cad;
}


Cadena& Cadena::operator =(const Cadena& other)
{
	if (this == &other)
		return *this;
	
	int longOther = strlen(other.cad);
	int longActual = strlen(cad);
	
	if(longOther != longActual)
	{
		delete [] cad;
		cad = new char[longOther + 1];
	}
	
	strcpy(cad, other.cad);
	
	return *this;
}
