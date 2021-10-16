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
	Cadena& aMinusculaMayuscula(bool aMayuscula);

public:
	Cadena();
	Cadena(const char* cad);
	Cadena(const Cadena& cad);
	Cadena(char c);
	Cadena(int n);
	Cadena(const Fecha& f);

	~Cadena();

    Cadena& aMayuscula();
	Cadena& aMinuscula();
	Cadena& trim(); // Podar: quita los espeacios y tabs a izq y der.

	Cadena& operator =(const Cadena& cadena);
	Cadena& operator +=(const Cadena& cad2);

	//Cadena operator +(const char* cad2);
	friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cadena);
	friend istream& operator >>(istream& ent, Cadena& cadena);

};




#endif // CADENA_H
