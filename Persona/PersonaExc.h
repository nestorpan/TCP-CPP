#ifndef PERSONAEXC_H
#define PERSONAEXC_H

#include "../Cadena/Cadena.h"


class PersonaExc
{
private:
    Cadena mensaje;

public:
    PersonaExc(const Cadena& mensaje);
    const Cadena& getMensaje() const;
};


#endif // PERSONAEXC_H
