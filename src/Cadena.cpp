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
	if(this == &other)
		return *this; // handle self assignment
	
	int longAct = strlen(this->cad);
	int longNueva = strlen(other.cad);
	
	if(longAct != longNueva)
	{
		delete [] this->cad;
		this->cad = new char[longNueva + 1];
	}
	
	strcpy(this->cad, other.cad);
	
	return *this;
}
