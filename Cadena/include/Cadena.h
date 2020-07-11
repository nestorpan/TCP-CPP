#ifndef CADENA_H
#define CADENA_H

#include <vector>
#include <iostream>

#include <Fecha.h>


#define TAM_BUF 501


using namespace std;


class Cadena
{
private:
	char* cad;
	
	Cadena(char* cad);
	
	int cantDigitos(int num);
	
public:
	Cadena(const char* cad = NULL);
	Cadena(int num);
	Cadena(const Fecha& f);
	
	///Sólo si utilizo memoria dinámica
	Cadena(const Cadena& otra); ///Constructor de copia
	~Cadena();
	Cadena& operator =(const Cadena& otra);
	
	Cadena operator +(const Cadena& cad2) const;
///	Cadena operator +(const char* cad2) const;
///	Cadena operator +(char car) const;
	Cadena& operator +=(const Cadena& cad2);
	char& operator [](int subindice);
	bool operator ==(const Cadena& otra);
	
	Cadena subcadena(int inicio, int fin) const;
	void split(char separador, vector<Cadena>& vSubcads) const;
	int getCantCaracteres() const;
	Cadena normalizar() const;
	Cadena& normalizar();
	Cadena reemplazar(const Cadena& que, const Cadena& por) const;
	Cadena& reemplazar(const Cadena& que, const Cadena& por);
	
///	friend Cadena operator +(const char* cad1, const Cadena& cad2);
///	friend Cadena operator +(const char* cad1, const char* cad2);
///	friend Cadena operator +(char car, const Cadena& cad2);
	
	double toDouble();
	
	friend ostream& operator <<(ostream& sal, const Cadena& cad);
	friend istream& operator >>(istream& ent, Cadena& cad);
};


#endif // CADENA_H
