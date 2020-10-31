#include <string.h>
#include "Cadena.h"

int Cadena::cantCall = 0;

Cadena::Cadena()
{
	this->cad = new char[1];
	this->cad[0] = '\0';

	cantCall++;

///    cout << "Llamando al contructor" << endl;

}

Cadena::Cadena(const char* cad)
{
	cantCall++;
///    cout << "Llamando al contructor" << endl;
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
	cantCall++;
///    cout << "Llamando al contructor" << endl;
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
	cantCall++;
///    cout << "Llamando al contructor" << endl;
	this->cad = new char[strlen(otra.cad) + 1];
	strcpy(this->cad, otra.cad);
}


Cadena::~Cadena()
{
    cantCall--;
///    cout << "Llamando al destructor" << endl;
    delete [] this->cad;
}

Cadena& Cadena::operator =(const Cadena& otra)
{
	int longThis = strlen(this->cad) + 1;
	int longOtra = strlen(otra.cad) + 1;

	if(longOtra != longThis)
	{
		delete [] this->cad;
		this->cad = new char[longOtra];
	}

	strcpy(this->cad, otra.cad);

	return *this;
}

istream& Cadena::leer(istream& ent, char hastaCar)
{
	size_t cantCar = 0;
	char c;
	int posIni = ent.tellg()-1;
	while((c = ent.get()) != EOF && c != hastaCar)
		cantCar++;

	if(cantCar == 0)
		return ent;

	int tellg = ent.tellg();
	ent.seekg(posIni);
	tellg = ent.tellg();

	if(strlen(this->cad) != cantCar)
	{
		delete [] this->cad;
		this->cad = new char[cantCar + 1];
	}

	ent.getline(this->cad, cantCar + 1, hastaCar);
	tellg = ent.tellg();

	return ent;
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
	int posIni = ent.tellg(); // obtiene la posición actual donde está el puntero al archivo

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

int Cadena::getCantCall()
{
    return this->cantCall;
}
/*
Cadena Cadena::operator +(const Cadena& otra) const
{
	char* concat = new char[strlen(this->cad) + strlen(otra.cad) + 1];

	strcpy(concat, this->cad);
	strcat(concat, otra.cad);

	return Cadena(concat);
}
*/
Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
	char* concat = new char[strlen(cad1.cad) + strlen(cad2.cad) + 1];

	strcpy(concat, cad1.cad);
	strcat(concat, cad2.cad);

	return Cadena(concat);
}

int Cadena::contarDigitos(int d)
{
    // 150
	int contDig = 1;

	if(d < 0)
	{
		d = -d;
		contDig++;
	}

	while((d / 10) > 0) {
		contDig++; // 3
        d /= 10;
	}

	return contDig;
}

vector<Cadena> Cadena::split(char separador) const
{
	vector<Cadena> vCad;
	int posAct = 0;
	int posSep;
	Cadena subCad;

	// this->cad = "Hola que tal"
	// vCad[0] = "Hola"
	// vCad[1] = "que"
	// vCad[2] = "tal"

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
	return subcadena(ini, strlen(this->cad));
}

bool Cadena::letrasYEspacios() const
{
	return true;
}
