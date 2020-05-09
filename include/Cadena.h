#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include <iostream>


using namespace std;


class Cadena
{
private:
	char* cad;
	Cadena(char* cad);
	
public:
	Cadena(const char* cad = NULL);
	
	///Sólo si utilizo memoria dinámica
	Cadena(const Cadena& otra); ///Constructor de copia
	~Cadena();
	Cadena& operator =(const Cadena& otra);
	
	Cadena operator +(const Cadena& cad2) const;
	Cadena& operator +=(const Cadena& cad2);
	Cadena subcadena(int inicio, int fin) const;
	void split(char separador, vector<Cadena>& vSubcads) const;
	int getCantCaracteres() const;
	
	friend Cadena operator +(const char* cad1, const Cadena& cad2);
	friend ostream& operator <<(ostream& sal, const Cadena& cad);
	friend istream& operator >>(istream& ent, Cadena& cad);
};


#endif // CADENA_H
