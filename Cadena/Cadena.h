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
	Cadena(int n);
	~Cadena();
	
	friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cadena);
};




#endif // CADENA_H
