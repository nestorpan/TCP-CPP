#include "FueraDeRangoExc.h"


FueraDeRangoExc::FueraDeRangoExc(const Cadena& mensaje)
{
    this->mensaje = mensaje;
}


const Cadena& FueraDeRangoExc::getMensaje() const
{
    return mensaje;
}
