#include <string.h>
#include <queue>
#include <iostream>
#include "Cadena.h"

using namespace std;


Cadena::Cadena()
{
    this->cadenaC = new char[1];
    cadenaC[0] = '\0';
}

Cadena::Cadena(const char* cadenaC)
{
    this->cadenaC = new char[strlen(cadenaC) + 1];
    strcpy(this->cadenaC, cadenaC);
}


Cadena::Cadena(char c)
{
    this->cadenaC = new char[2];
    cadenaC[0] = c;
    cadenaC[1] = '\0';
}


Cadena::Cadena(int numero)
{
    this->cadenaC = new char[cantDigitos(numero) + (numero < 0 ? 1 : 0) + 1];
    sprintf(this->cadenaC, "%d", numero);
}


Cadena::Cadena(const Cadena& otra)
{
    this->cadenaC = new char[strlen(otra.cadenaC) + 1];
    strcpy(this->cadenaC, otra.cadenaC);
}

// Privado
Cadena::Cadena(char* cadenaC)
{
    this->cadenaC = cadenaC;
}

Cadena::~Cadena()
{
//    cout << "Ejecutando Destructor ..." << endl;
    delete [] cadenaC;
}


Cadena& Cadena::operator =(const Cadena& otra)
{
    if (this == &otra)
        return *this;

    if(strlen(this->cadenaC) != strlen(otra.cadenaC))
    {
        delete [] this->cadenaC;
        this->cadenaC = new char[strlen(otra.cadenaC) + 1];
    }

    strcpy(this->cadenaC, otra.cadenaC);

    return *this;
}


Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
/*
    Cadena concat;
    delete [] concat.cadenaC; //TODO: Implementar constructor privado que no copia la cadena.

    concat.cadenaC = new char[strlen(cad1.cadenaC) + strlen(cad2.cadenaC) + 1];
    strcpy(concat.cadenaC, cad1.cadenaC);
    strcat(concat.cadenaC, cad2.cadenaC);
    return concat;
*/
    char* cadenaConcat = new char[strlen(cad1.cadenaC) + strlen(cad2.cadenaC) + 1];
    strcpy(cadenaConcat, cad1.cadenaC);
    strcat(cadenaConcat, cad2.cadenaC);
    return Cadena(cadenaConcat);
}


ostream& operator <<(ostream& os, const Cadena& cadena)
{
    os << cadena.cadenaC;
    return os;
}


istream& operator >>(istream& is, Cadena& cadena)
{
    queue<char> colaChars;
    char c;

    while((c = is.get()) != '\n' && c != EOF)
        colaChars.push(c);

    if(strlen(cadena.cadenaC) != colaChars.size())
    {
        delete [] cadena.cadenaC;
        cadena.cadenaC = new char[colaChars.size() + 1];
    }

   	int i = 0;
    while(!colaChars.empty())
    {
        cadena.cadenaC[i++] = colaChars.front();
        colaChars.pop();
    }

    cadena.cadenaC[i] = '\0';

    return is;
}


int Cadena::cantDigitos(int numero)
{
    int cant = 1;

    while((numero /= 10) != 0)
        cant++;

    return cant;
}


bool Cadena::esFinDeLinea(char c)
{
    return c == '\r' || c == '\n';
}
