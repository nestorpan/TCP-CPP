#ifndef FUERADERANGOEXC_H
#define FUERADERANGOEXC_H

#include "Cadena.h"


class FueraDeRangoExc
{
private:
    Cadena mensaje;
    
public:
    FueraDeRangoExc(const Cadena& mensaje);

    const Cadena& getMensaje() const;
};


#endif // FUERADERANGOEXC_H
