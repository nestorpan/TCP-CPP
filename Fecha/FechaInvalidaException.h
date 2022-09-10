#ifndef FECHA_INVALIDA_EXCEPTION_H
#define FECHA_INVALIDA_EXCEPTION_H

#include <string>

using namespace std;


class FechaInvalidaException
{
private:
    string mensaje;

public:
    FechaInvalidaException(string mensaje);
    string getMensaje() const;
};


inline FechaInvalidaException::FechaInvalidaException(string mensaje)
: mensaje(mensaje)
{}


inline string FechaInvalidaException::getMensaje() const
{
    return mensaje;
}


#endif // FECHA_INVALIDA_EXCEPTION_H
