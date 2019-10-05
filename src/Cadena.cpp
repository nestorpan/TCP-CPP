#include <string.h>
#include "Cadena.h"


Cadena::Cadena(char* cad)
{
	this->cad = cad;
}


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


Cadena::Cadena(char c)
{
	this->cad = new char[2];
	this->cad[0] = c;
	this->cad[1] = '\0';
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


Cadena Cadena::operator +(const Cadena& other) const
{
	char* concat = new char[strlen(this->cad) + strlen(other.cad) + 1];
	
	strcpy(concat, this->cad);
	strcat(concat, other.cad);
	
	return Cadena(concat);
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	sal << cadena.cad;
	
	return sal;
}
