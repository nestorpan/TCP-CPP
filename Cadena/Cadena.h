#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;


class Cadena
{
private:
    char* cadenaC;

public:
    Cadena();
    Cadena(const char* cadenaC);

    // Estos 3 m�todos se deben implementtar al trabajar con memoria din�mica
    Cadena(const Cadena& cadena);
    ~Cadena();
    Cadena& operator =(const Cadena& cadena);

    Cadena operator +(const Cadena& cadena) const;
    Cadena& operator +=(const Cadena& cadena);
    bool operator ==(const Cadena& cadena) const;
    bool operator !=(const Cadena& cadena) const;
    bool operator <(const Cadena& cadena) const;
    bool operator <=(const Cadena& cadena) const;
    bool operator >(const Cadena& cadena) const;
    bool operator >=(const Cadena& cadena) const;

    char& operator [](int subindice);
    const char& operator [](int subindice) const;

    const char* getCadenaC() const;
    int getLongitud() const;

    friend ostream& operator <<(ostream& os, const Cadena& cadena);
};
//ostream& operator <<(ostream& os, const Cadena& cadena);


#endif // CADENA_H
