#include <string.h>
#include <vector>

#include <Cadena.h>
#include <Fecha.h>


Cadena::Cadena(char* cad)
{
	this->cad = cad;
}


Cadena::Cadena(const char* cad)
{
	if(!cad)
	{
		this->cad = new char[1];
		this->cad[0] = '\0';
		return;
	}
	
	this->cad = new char[strlen(cad) + 1];
	strcpy(this->cad, cad);
}


///Constructor de copia
Cadena::Cadena(const Cadena& otra)
{
	this->cad = new char[strlen(otra.cad) + 1];
	strcpy(this->cad, otra.cad);
}


Cadena::Cadena(const Fecha& f)
{
	int d, m, a;
	
	f.getDma(d, m, a);
	
	int longCad = (d >= 10? 2 : 1) + (m >= 10? 2 : 1) + 4 + 2;
	
	this->cad = new char[longCad + 1];
	
	sprintf(this->cad, "%d/%d/%d", d, m, a);
}


Cadena::Cadena(int num)
{
	this->cad = new char[cantDigitos(num) + 1];
	sprintf(this->cad, "%d", num);
}


Cadena::~Cadena()
{
	delete [] this->cad;
}


int Cadena::cantDigitos(int num)
{
	int contDig = 0;
	
	if(num < 0)
	{
		contDig++;
		num = -num;
	}
	
	while(num /= 10 > 0)
		contDig++;
	
	contDig++;
	
	return contDig;
}


Cadena& Cadena::operator =(const Cadena& otra)
{
	int viejaLong = strlen(this->cad);
	int nuevaLong = strlen(otra.cad);
	
	if(viejaLong != nuevaLong)
	{
		delete [] this->cad;
		this->cad = new char[nuevaLong + 1];
	}
	
	strcpy(this->cad, otra.cad);
	
	return *this;
}


Cadena Cadena::operator +(const Cadena& cad2) const
{
	char* concatAux = new char[strlen(this->cad) + strlen(cad2.cad) + 1];
	
	strcpy(concatAux, this->cad);
	strcat(concatAux, cad2.cad);
	
//	Cadena concat(concatAux);
	
	return Cadena(concatAux);//concat;
}


bool Cadena::operator ==(const Cadena& otra)
{
	return strcmp(this->cad, otra.cad) == 0;
}


/**
Cadena& operator +=(const Cadena& cad2);
Cadena subcadena(int inicio, int fin) const;
int getCantCaracteres() const;
*/


void Cadena::split(char separador, vector<Cadena>& vSubcads) const
{
	char* copia = new char[strlen(this->cad) + 1];
	strcpy(copia, this->cad);
	char* act = copia;
	
	char* dirSep;
	
	while((dirSep = strchr(act, separador)))
	{
		*dirSep = '\0';
		vSubcads.push_back(Cadena((const char*)act));
		act = dirSep + 1;
	}
	
	vSubcads.push_back(Cadena((const char*)act));
	
	delete [] copia;
}


char& Cadena::operator [](int subindice)
{
	///TODO: Validar limites.
	
	return this->cad[subindice];
}


double Cadena::toDouble()
{
	return atof(this->cad);
}


ostream& operator <<(ostream& sal, const Cadena& cad)
{
	sal << cad.cad;
	return sal;
}


istream& operator >>(istream& ent, Cadena& cad)
{
	char buffer[TAM_BUF];
	
	ent.getline(buffer, TAM_BUF, '\n');
	
	int nuevaLong = strlen(buffer);
	int viejaLong = strlen(cad.cad);
	
	if(viejaLong != nuevaLong)
	{
		delete [] cad.cad;
		cad.cad = new char[nuevaLong + 1];
	}
	
	strcpy(cad.cad, buffer);
	
	return ent;
}
