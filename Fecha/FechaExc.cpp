#include "FechaExc.h"


FechaExc::FechaExc(const string& mensaje)
{
    this->mensaje = mensaje;
}


const string& FechaExc::getMensaje() const
{
    return this->mensaje;
}
