#include <string.h>
#include <stdlib.h>
#include "Cadena.h"


Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';
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


Cadena::Cadena(int n)
{
	this->cad = new char[cantDigitos(n) + 1];
	sprintf(this->cad, "%d", n);
}

Cadena::Cadena(double n)
{
    // TODO cantDigitos(n)
	this->cad = new char[n + 1];
	sprintf(this->cad, "%.2f", n);
}

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

	return Cadena(vConcat); ///Llama al constructor privado que no copia la cadena.
}


ostream& operator <<(ostream& sal, const Cadena& cad)
{
	return sal << cad.cad;
}


int Cadena::cantDigitos(int n)
{
	int cantDig = 1;

	while((n /= 10) > 0)
		cantDig++;

	return cantDig;
}
