#include <string.h>
#include "Cadena.h"


Cadena::Cadena(char* cad)
{
	this->cad = cad;
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


///Constructor de copia
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
	int viejaLong = strlen(this->cad);
	int nuevaLong = strlen(otra.cad);
	
	if(viejaLong != nuevaLong)
	{
		delete [] this->cad;
		this->cad = new char[nuevaLong + 1];
	}
	
	strcpy(this->cad, otra.cad);
	
	return *this;
}


Cadena Cadena::operator +(const Cadena& cad2) const
{
	char* concatAux = new char[strlen(this->cad) + strlen(cad2.cad) + 1];
	
	strcpy(concatAux, this->cad);
	strcat(concatAux, cad2.cad);
	
	Cadena concat(concatAux);
	
	return concat;
}

/**
Cadena& operator +=(const Cadena& cad2);
Cadena subcadena(int inicio, int fin) const;
void split(char separador, vector& vSubcads) const;
int getCantCaracteres() const;
*/


ostream& operator <<(ostream& sal, const Cadena& cad)
{
	sal << cad.cad;
	return sal;
}
