#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

using namespace std;

class Fecha;


class Cadena
{
private:
    char* cadenaC;

    static int cantDigitos(int numero);
    static bool esFinDeLinea(char c);

    Cadena(char* cadenaC); // Constructor privado, que no copia la cadena.

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
    vector<Cadena> split(char separador) const;
    unsigned toUnsigned() const;
    int toInt() const;
    Fecha toFecha() const;

    friend Cadena operator +(const Cadena& cadena1, const Cadena& cadena2);
    friend ostream& operator <<(ostream& os, const Cadena& cadena);
    friend istream& operator >>(istream& is, Cadena& cadena);
};


#endif // CADENA_H
