#include <string.h>
#include "Cadena.h"


Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';
}


Cadena::Cadena(const char* cad)
{
	if(!cad)
	{
		this->cad = new char[1];
		this->cad[0] = '\0';
		return;
	}
	
	this->cad = new char[strlen(cad) + 1];
	strcpy(this->cad, cad);
}


Cadena::Cadena(char* cad)
{
	this->cad = cad;
}


Cadena::Cadena(const Cadena& otra)
{
	this->cad = new char[strlen(otra.cad) + 1];
	strcpy(this->cad, otra.cad);
}


Cadena::~Cadena()
{
	delete [] this->cad;
}


Cadena& Cadena::operator =(const Cadena& otra)
{
	int longVieja = strlen(this->cad) + 1;
	int longNueva = strlen(otra.cad) + 1;
	
	if(longNueva != longVieja)
	{
		delete [] this->cad;
		this->cad = new char[longNueva];
	}
	
	strcpy(this->cad, otra.cad);
	
	return *this;
}


Cadena Cadena::operator +(const Cadena& otra) const
{
	char* concat = new char[strlen(this->cad) + strlen(otra.cad) + 1];
	
	strcpy(concat, this->cad);
	strcat(concat, otra.cad);
	
	return Cadena(concat);
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	sal << cadena.cad;
	return sal;
}
