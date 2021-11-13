#include "Figura.h"


Figura::Figura(const Cadena& nombre)
{
    this->nombre = nombre;
}

const Cadena& Figura::getNombre() const
{
    return nombre;
}
