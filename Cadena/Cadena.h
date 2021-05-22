#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;


class Cadena
{
private:
	char* cad;
	
	Cadena(char* cad);
	
	static int cantDigitos(int n);
	
public:
	Cadena();
	Cadena(const Cadena& otra);
	Cadena(const char* cad);
	Cadena(char c);
	Cadena(int n);
	Cadena(float n);
	~Cadena();
	
	friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cad);
	friend istream& operator >>(istream& ent, Cadena& cad);
	
	bool vacia() const;
};


#endif // CADENA_H
