#include <string.h>
#include <queue>
#include "FueraDeRangoExc.h"
#include "Cadena.h"


Cadena::Cadena()
{
    cadena = new char[1];
    cadena[0] = '\0';
}


Cadena::Cadena(char* cadena)
{
    this->cadena = cadena;
}


Cadena::Cadena(const char* cadena)
{
    //TODO: Validar si cadena es NULL.
    this->cadena = new char[strlen(cadena) + 1];
    strcpy(this->cadena, cadena);
}


Cadena::Cadena(const Fecha& fecha)
{
    this->cadena = new char[11];
    int d, m, a;
    fecha.getDMA(d, m, a);

    sprintf(this->cadena, "%02d/%02d/%4d", d, m, a);
}


Cadena::Cadena(char c)
{
    cadena = new char[2];
    cadena[0] = c;
    cadena[1] = '\0';
}


Cadena::Cadena(int num)
{
    cadena = new char[cantDigitos(num) + 1];
    sprintf(cadena, "%d", num);
}


Cadena::Cadena(const Cadena& otra)
{
    this->cadena = new char[strlen(otra.cadena) + 1];
    strcpy(this->cadena, otra.cadena);
}


Cadena::~Cadena()
{
    delete [] cadena;
}


bool Cadena::esEnteroPositivo() const
{
    char* act = cadena;

    if(!*act || *act == '-')
        return false;

    while(*act && *act >= '0' && *act <= '9')
        act++;

    return !*act;
}


unsigned Cadena::longitud() const
{
    return strlen(cadena);
}


Cadena& Cadena::operator=(const Cadena& otra)
{
    if(strlen(this->cadena) != strlen(otra.cadena))
    {
        delete [] this->cadena;
        this->cadena = new char[strlen(otra.cadena) + 1];
    }

    strcpy(this->cadena, otra.cadena);

    return *this;
}


Cadena& Cadena::operator+=(const Cadena& other)
{
    char* concatC = new char[strlen(this->cadena) + strlen(other.cadena) + 1];
    strcpy(concatC, this->cadena);
    strcat(concatC, other.cadena);
    delete [] this->cadena;
    this->cadena = concatC;

    return *this;
}


char Cadena::operator[](int i) const
{
    if(i >= 0 && i > (int)strlen(this->cadena))
    {
        throw FueraDeRangoExc("Indice fuera de rango");
    }

    return this->cadena[i];
}


Cadena operator+(const Cadena& cad1, const Cadena& cad2)
{
    char* concatC = new char[strlen(cad1.cadena) + strlen(cad2.cadena) + 1];

    strcpy(concatC, cad1.cadena);
    strcat(concatC, cad2.cadena);

    return Cadena(concatC);
}


int Cadena::cantDigitos(int num)
{
    int cant = 1;

    while((num /= 10) != 0)
        cant++;

    return cant;
}


vector<Cadena> Cadena::split(char delim) const
{
    vector<Cadena> campos;

    const char* iniCampo = this->cadena;
    char* pDelim;

    pDelim = strchr(iniCampo, delim);
    while(pDelim)
    {
        *pDelim = '\0';
        campos.push_back(Cadena(iniCampo));
        iniCampo = pDelim + 1;
        *pDelim = delim;
        pDelim = strchr(iniCampo, delim);
    }

    campos.push_back(Cadena(iniCampo));

    return campos;
}


int Cadena::toInt() const
{
    int num = 0;
    char* act = cadena;

    while(*act)
    {
        num *= 10;
        num += *act - '0';
        act++;
    }

    return num;
}


ostream& operator<<(ostream& sal, const Cadena& cad)
{
    sal << cad.cadena;
    return sal;
}

/*
istream& operator>>(istream& is, Cadena& cad)
{
    char cadena[500];
    is.getline(cadena, 500);

    if(strlen(cad.cadena) != strlen(cadena))
    {
        delete [] cad.cadena;
        cad.cadena = new char[strlen(cadena) + 1];
    }

    strcpy(cad.cadena, cadena);
    return is;
}
*/

istream& operator>>(istream& is, Cadena& cad)
{
    queue<char> cola;
    char c;

    while((c = is.get()) != EOF && c != '\n')
        cola.push(c);

    if(strlen(cad.cadena) != cola.size())
    {
        delete [] cad.cadena;
        cad.cadena = new char[cola.size() + 1];
    }

    int i = 0;
    while(!cola.empty())
    {
        cad.cadena[i] = cola.front();
        cola.pop();
        i++;
    }

    cad.cadena[i] = '\0';

    is.ignore(1);
    
    return is;
}
