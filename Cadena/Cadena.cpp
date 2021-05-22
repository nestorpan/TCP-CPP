#include <string.h>
#include <stdlib.h>
#include <queue>

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


bool Cadena::vacia() const
{
	return *this->cad == '\0';
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	return sal << cadena.cad;
}


istream& operator >>(istream& ent, Cadena& cadena)
{
	size_t cantCar = 0;
	char c;
	queue<char> colaChars;
	
	while((c = ent.get()) != EOF && c != '\n')
	{
		cantCar++;
		colaChars.push(c); /// Encolar
	}
	
	if(strlen(cadena.cad) != cantCar)
	{
		delete [] cadena.cad;
		cadena.cad = new char[cantCar + 1];
	}
	
	char* pc = cadena.cad;
	
	while(!colaChars.empty()) /// Cola Vacía
	{
		*pc = colaChars.front(); /// Ver Frente de Cola
		colaChars.pop(); /// Desencolar
		++pc;
	}
	
	*pc = '\0';
	
	ent.peek(); /// Para prender el flag EOF, si estoy al final del archivo, pero no intenté leer.
	
	return ent;
}


int Cadena::cantDigitos(int n)
{
	int cantDig = 1;
	
	while((n /= 10) > 0)
		cantDig++;
	
	return cantDig;
}








