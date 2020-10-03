#include <string.h>
#include "Cadena.h"

int Cadena::cantCall = 0;

Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';

	cantCall++;

    cout << "Llamando al contructor" << endl;

}

Cadena::Cadena(const char* cad)
{
	cantCall++;
    cout << "Llamando al contructor" << endl;
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
	cantCall++;
    cout << "Llamando al contructor" << endl;
	this->cad = cad;
}

Cadena::Cadena(const Cadena& otra)
{
	cantCall++;
    cout << "Llamando al contructor" << endl;
	this->cad = new char[strlen(otra.cad) + 1];
	strcpy(this->cad, otra.cad);
}


Cadena::~Cadena()
{
    cantCall--;
    cout << "Llamando al destructor" << endl;
    delete [] this->cad;
}

Cadena& Cadena::operator =(const Cadena& otra)
{
	int longThis = strlen(this->cad) + 1;
	int longOtra = strlen(otra.cad) + 1;

	if(longOtra != longThis)
	{
		delete [] this->cad;
		this->cad = new char[longOtra];
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


int Cadena::getCantCall()
{
    return this->cantCall;
}
