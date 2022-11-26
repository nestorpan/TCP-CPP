#ifndef NULL_POINTER_EXCEPTION_H
#define NULL_POINTER_EXCEPTION_H

#include "../Cadena/Cadena.h"


class NullPointerException
{
private:
    Cadena mensaje;

public:
    NullPointerException(const Cadena& mensaje) : mensaje(mensaje) {};

    const Cadena& getMensaje() const { return mensaje; };
};


#endif // NULL_POINTER_EXCEPTION_H