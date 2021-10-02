#include "Cadena.h"
#include <string.h>
#include <queue>

#include <iostream>

#ifdef _WIN32
    #define CRLF '\n'
#elif defined __unix__
    #define CRLF '\r'
#elif defined __APPLE__
    #define CRLF '\n'
#endif

using namespace std;

int cantDigitos(int n);

Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';
	this->tam = 0;
}

/// Público
Cadena::Cadena(const char* cad)
{
    this->tam = strlen(cad);
	this->cad = new char[this->tam + 1];
	strcpy(this->cad, cad);
}

Cadena::Cadena(char c)
{
	this->cad = new char[2];
	this->cad[0] = c;
	this->cad[1] = '\0';
	this->tam = 1;
}

Cadena::Cadena(int n)
{
    this->tam = cantDigitos(n);
	this->cad = new char[cantDigitos(n) + 1];
	sprintf(this->cad, "%d", n);
}

Cadena::Cadena(const Cadena& cadena)
{
	this->cad = new char[cadena.tam + 1];
	strcpy(this->cad, cadena.cad);
	this->tam = cadena.tam;
}

/// Privado
Cadena::Cadena(char* cad)
{
	this->cad = cad;
	this->tam = strlen(cad);
}

Cadena::~Cadena()
{
    delete [] this->cad;
}


Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
	char* vConcat = new char[cad1.tam + cad2.tam + 1];
	strcpy(vConcat, cad1.cad);
	strcat(vConcat, cad2.cad);

	return Cadena(vConcat);
}

Cadena& Cadena::operator =(const Cadena& cadena)
{
	if(this->tam != cadena.tam)
	{
		delete [] this->cad;
		this->cad = new char[cadena.tam + 1];
		this->tam = cadena.tam;
	}

	strcpy(this->cad, cadena.cad);

	return *this;
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	return sal << cadena.cad;
}

istream& operator >>(istream& ent, Cadena& cadena)
{
	queue<char> colaCar;
	unsigned cantCar = 0;
	char c;

	while((c = ent.get()) != EOF && c != CRLF)
	{
		colaCar.push(c);
		cantCar++;
	}

	if(cadena.tam != cantCar)
	{
		cadena.tam = cantCar;
		delete [] cadena.cad;
		cadena.cad = new char[cadena.tam + 1];
	}

	char* act = cadena.cad;
	while(!colaCar.empty())
	{
		*act = colaCar.front();
		colaCar.pop();
		act++;
	}

	*act = '\0';

	return ent;
}

int cantDigitos(int n)
{
	int cantDig = 1;

	while((n /= 10) > 0)
		cantDig++;

	return cantDig;
}

Cadena& Cadena::aMayuscula()
{
	return aMinusculaMayuscula(false);
}

Cadena& Cadena::aMinuscula()
{
	return aMinusculaMayuscula(true);
}

Cadena& Cadena::aMinusculaMayuscula(bool aMinuscula)
{
	char* act = this->cad;

	while(*act)
	{
		*act = aMinuscula?tolower(*act):toupper(*act);
		act++;
	}

	return *this;
}
