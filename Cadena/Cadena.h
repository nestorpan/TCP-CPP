#ifndef CADENA_H
#define CADENA_H

#include <iostream>

#include "../Fecha/Fecha.h"

using namespace std;


class Cadena
{
private:
	char* cad;
	unsigned tam;
	
	Cadena(char* cad);
	
public:
	Cadena();
	Cadena(const char* cad);
	Cadena(char c);
	Cadena(int n);
	Cadena(const Fecha& f);
	
	Cadena(const Cadena& cad);
	~Cadena();
	Cadena& operator =(const Cadena& cadena);
	Cadena& operator =(const string& str);

	Cadena& operator +=(const Cadena& cad2);
	
	Cadena& aMayuscula();
	Cadena& aMinuscula();
	
	friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cadena);
	friend istream& operator >>(istream& ent, Cadena& cadena);
};


#endif // CADENA_H
