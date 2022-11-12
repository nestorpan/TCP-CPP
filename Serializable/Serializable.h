#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>
#include <map>

class Cadena;

using namespace std;


class Serializable
{
    static map<Cadena, Serializable*> objetos;

public:
    virtual void serializar(ostream& os, bool serializaNombre = false) const = 0;
    virtual Serializable* deserializarDin(istream& is) = 0;
    virtual void deserializar(istream& is) = 0;
    static Serializable* deserializarStatic(istream& is);
};


#endif // SERIALIZABLE_H
