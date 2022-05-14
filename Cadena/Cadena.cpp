#include <string.h>
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
    this->cadena = new char[strlen(cadena) + 1];
    strcpy(this->cadena, cadena);
}


Cadena::Cadena(const Fecha& fecha)
{
    this->cadena = new char[11]; // 01/01/2000 + 1 = 11
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
    cout << "Destruyendo Cadena ==>> " << cadena << endl;
    delete [] cadena;
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

    while((num /= 10)!= 0)
        cant++;

    return cant;
}

/*
char* Cadena::getCadena() const
{
    return cadena;
}
*/
