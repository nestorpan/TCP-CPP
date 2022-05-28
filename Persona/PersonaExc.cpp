#include "PersonaExc.h"


PersonaExc::PersonaExc(const Cadena& mensaje)
{
    this->mensaje = mensaje;
}


const Cadena& PersonaExc::getMensaje() const
{
    return mensaje;
}
