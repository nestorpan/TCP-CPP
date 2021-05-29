#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

using namespace std;


class Cadena
{
private:
	char* cad;
	
	Cadena(char* cad);
	
	static int cantDigitos(int n);
	static char* proximoSeparador(const char* origen, char separador);
	
public:
	Cadena();
	Cadena(const char* cad);
	Cadena(char c);
	Cadena(int n);
	Cadena(float n);
	
	Cadena(const Cadena& otra);
	~Cadena();
	Cadena& operator =(const Cadena& otra);
	
	Cadena& operator +=(const Cadena& otra);
	
	bool vacia() const;
	vector<Cadena> split(char separador);
		
	friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cad);
	friend istream& operator >>(istream& ent, Cadena& cad);
};


#endif // CADENA_H
