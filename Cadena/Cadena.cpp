#include <string.h>

#include "Cadena.h"


int cantDigitos(int n);


Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';
}

/// Público
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


Cadena::Cadena(int n)
{
	this->cad = new char[cantDigitos(n) + 1];
	sprintf(this->cad, "%d", n);
}


/// Privado
Cadena::Cadena(char* cad)
{
	this->cad = cad;
}


Cadena::~Cadena()
{
	delete [] this->cad;
}


Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
	char* vConcat = new char[strlen(cad1.cad) + strlen(cad2.cad) + 1];
	strcpy(vConcat, cad1.cad);
	strcat(vConcat, cad2.cad);
	
	return Cadena(vConcat);
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	return sal << cadena.cad;
}


int cantDigitos(int n)
{
	int cantDig = 1;
	
	while((n /= 10) > 0)
		cantDig++;
	
	return cantDig;
}















