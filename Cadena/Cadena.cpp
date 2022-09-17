#include <string.h>
#include "Cadena.h"


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

Cadena::Cadena(const Cadena& otra)
{
    this->cadenaC = new char[strlen(otra.cadenaC) + 1];
    strcpy(this->cadenaC, otra.cadenaC);
}


Cadena::~Cadena()
{
    cout << "Ejecutando Destructor ..." << endl;
    delete [] this->cadenaC;
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


Cadena Cadena::operator +(const Cadena& otra) const
{
    Cadena concat;
    delete [] concat.cadenaC;
    concat.cadenaC = new char[strlen(this->cadenaC) + strlen(otra.cadenaC) + 1];
    strcpy(concat.cadenaC, this->cadenaC);
    strcat(concat.cadenaC, otra.cadenaC);
    return concat;
}

const char* Cadena::getCadenaC() const
{
    return this->cadenaC;
}


ostream& operator <<(ostream& os, const Cadena& cadena)
{
    os << cadena.cadenaC;
    return os;
}
