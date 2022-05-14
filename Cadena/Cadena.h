#ifndef CADENA_H
#define CADENA_H

#include "../Fecha/Fecha.h"


class Cadena
{
private:
    char* cadena;

    Cadena(char* cad);
    
    static int cantDigitos(int num);

public:
    Cadena();
    Cadena(const char* cad);
    Cadena(const Cadena& other);
    Cadena(const Fecha& fecha);
    Cadena(char c);
    Cadena(int num);

    ~Cadena();
    
    Cadena& operator=(const Cadena& other);
    
    friend Cadena operator+(const Cadena& cad1, const Cadena& cad2);
};


#endif // CADENA_H
