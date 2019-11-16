#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;


class Cadena
{
private:
	char* cad;
	Cadena(char* cad);
	
public:
	Cadena();
	Cadena(const char* cad);
	Cadena(char c);
	Cadena(const Cadena& other);
	~Cadena();
	Cadena& operator =(const Cadena& other);
	Cadena operator +(const Cadena& other) const;
	Cadena& operator +=(const Cadena& other);
	
	static int comparar(const Cadena& c1, const Cadena& c2);
	
	friend ostream& operator <<(ostream& sal, const Cadena& cadena);
	friend istream& operator >>(istream& ent, Cadena& cadena);
};


#endif // CADENA_H
