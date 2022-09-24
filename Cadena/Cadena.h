#ifndef CADENA_H
#define CADENA_H

#include <iostream>

using namespace std;


class Cadena
{
private:
    char* cadenaC;

    static int cantDigitos(int numero);
    static bool esFinDeLinea(char c);

public:
    Cadena();
    Cadena(const char* cadenaC);
    Cadena(char c);
    Cadena(int numero);

    Cadena(const Cadena& cadena);
    ~Cadena();
    Cadena& operator =(const Cadena& cadena);

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

    friend Cadena operator +(const Cadena& cadena1, const Cadena& cadena2);
    friend ostream& operator <<(ostream& os, const Cadena& cadena);
    friend istream& operator >>(istream& is, Cadena& cadena);
};


#endif // CADENA_H
