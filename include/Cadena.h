#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;


class Cadena
{
private:
	char* cad;
	
public:
	Cadena();
	Cadena(const char* cad);
	Cadena(const Cadena& other);
	~Cadena();
	Cadena& operator =(const Cadena& other);
};


#endif // CADENA_H
