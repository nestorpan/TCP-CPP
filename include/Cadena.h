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
	Cadena operator +(const Cadena& cad2) const;
	
	friend ostream& operator <<(ostream& sal, const Cadena& cad);
};


#endif // CADENA_H
