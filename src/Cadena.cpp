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
	cad = new char[2];
	
	cad[0] = c;
	cad[1] = '\0';
}


Cadena::Cadena(const Cadena& other)
{
	this->cad = new char[strlen(other.cad) + 1];
	strcpy(this->cad, other.cad);
}


Cadena::~Cadena()
{
///	cout << "Ejecutando destructor ..." << endl;
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


Cadena Cadena::operator +(const Cadena& cad2) const
{
	char* aux = new char[strlen(this->cad) + strlen(cad2.cad) + 1];
	
	strcpy(aux, this->cad);
	strcat(aux, cad2.cad);
/**	
	Cadena concat(aux);
	return concat;
*/
	return Cadena(aux);
}


ostream& operator <<(ostream& sal, const Cadena& cad)
{
	sal << cad.cad;
	return sal;
}


int Cadena::comparar(const Cadena& c1, const Cadena& c2)
{
	return strcmp(c1.cad, c2.cad);
}


istream& operator >>(istream& ent, Cadena& cad)
{
	char* aux = new char[500];
	
	ent.getline(aux, 500);
	
	int viejaLong = strlen(cad.cad);
	int nuevaLong = strlen(aux);
	
	if(viejaLong != nuevaLong)
	{
		delete [] cad.cad;
		cad.cad = new char[nuevaLong + 1];
	}
	
	strcpy(cad.cad, aux);
	
	delete [] aux;
	
	return ent;
}
