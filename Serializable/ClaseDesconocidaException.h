#ifndef CLASE_DESCONOCIDA_EXCEPTION_H
#define CLASE_DESCONOCIDA_EXCEPTION_H

#include "../Cadena/Cadena.h"


class ClaseDesconocidaException
{
private:
    Cadena mensaje;

public:
    ClaseDesconocidaException(const Cadena& mensaje) : mensaje(mensaje) {};

    inline const Cadena& getMensaje() const { return mensaje; };
};


#endif // CLASE_DESCONOCIDA_EXCEPTION_H
