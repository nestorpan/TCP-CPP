#include <string.h>

#include "Cadena.h"


Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';
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


Cadena::Cadena(char* cad)
{
	this->cad = cad;
}


Cadena::Cadena(char c)
{
	this->cad = new char[2];
	this->cad[0] = c;
	this->cad[1] = '\0';
}


Cadena::Cadena(int d)
{
	int cantDig = contarDigitos(d);
	
	this->cad = new char[cantDig + 1];
	sprintf(this->cad, "%d", d);
}


Cadena::Cadena(const Cadena& otra)
{
	this->cad = new char[strlen(otra.cad) + 1];
	strcpy(this->cad, otra.cad);
}


Cadena::~Cadena()
{
	delete [] this->cad;
}


Cadena& Cadena::operator =(const Cadena& otra)
{
	int longVieja = strlen(this->cad) + 1;
	int longNueva = strlen(otra.cad) + 1;
	
	if(longNueva != longVieja)
	{
		delete [] this->cad;
		this->cad = new char[longNueva];
	}
	
	strcpy(this->cad, otra.cad);
	
	return *this;
}


Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
	char* concat = new char[strlen(cad1.cad) + strlen(cad2.cad) + 1];
	
	strcpy(concat, cad1.cad);
	strcat(concat, cad2.cad);
	
	return Cadena(concat);
}


int Cadena::contarDigitos(int d)
{
	int contDig = 1;
	
	if(d < 0)
	{
		d = -d;
		contDig++;
	}
	
	while((d /= 10) > 0)
		contDig++;
	
	return contDig;
}

///template
vector<Cadena> Cadena::split(char separador) const
{
	vector<Cadena> vCad;
	int posAct = 0;
	int posSep;
	Cadena subCad;
	
	while((posSep = this->posCaracter(separador, posAct)) >= 0)
	{
		subCad = this->subcadena(posAct, posSep);
		vCad.push_back(subCad);
		posAct = posSep + 1;
	}
	
	subCad = this->subcadena(posAct);
	vCad.push_back(subCad);
	
	return vCad;
}


int Cadena::posCaracter(char c, int ini) const
{
	char* dirIni = strchr(this->cad + ini, c);
	
	if(!dirIni)
		return -1;
	
	return (int)(dirIni - this->cad);
}


Cadena Cadena::subcadena(int ini, int fin) const
{
	char* subcad = new char[/*(fin - ini) + 1*/ 100];
	char* ult = this->cad + fin - 1;
	char* orig;
	char* dest;
	
	for(orig = this->cad + ini, dest = subcad; orig <= ult; orig++, dest++)
		*dest = *orig;
	
	*dest = '\0';
	
	return Cadena(subcad);
}


Cadena Cadena::subcadena(int ini) const
{
	int fin = strlen(this->cad);
	
	return subcadena(ini, fin);
}


istream& Cadena::leer(istream& ent, char hastaCar)
{
	size_t cantCar = 0;
	char c;
	int posIni = ent.tellg();
	while((c = ent.get()) != EOF && c != hastaCar)
		cantCar++;
	
	if(cantCar == 0)
		return ent;
	
	ent.seekg(posIni);
	
	if(strlen(this->cad) != cantCar)
	{
		delete [] this->cad;
		this->cad = new char[cantCar + 1];
	}
	
	ent.getline(this->cad, cantCar + 1, hastaCar);
	
	return ent;
}


bool Cadena::letrasYEspacios() const
{
	return true;
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	sal << cadena.cad;
	return sal;
}


istream& operator >>(istream& ent, Cadena& cadena)
{
	size_t cantCar = 0;
	char c;
	int posIni = ent.tellg();
	while((c = ent.get()) != EOF && c != '\n')
		cantCar++;
	
	if(cantCar == 0)
		return ent;
	
	ent.seekg(posIni);
	
	if(strlen(cadena.cad) != cantCar)
	{
		delete [] cadena.cad;
		cadena.cad = new char[cantCar + 1];
	}
	
	ent.getline(cadena.cad, cantCar + 1);
	
	return ent;
}

















