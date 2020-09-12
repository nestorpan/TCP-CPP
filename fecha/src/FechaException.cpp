#include "FechaException.h"
#include <string>

using namespace std;

FechaException::FechaException(const string& mensaje)
{
    this->mensaje = mensaje;
}

const string& FechaException::getMensaje() const
{
    return this->mensaje;
}
