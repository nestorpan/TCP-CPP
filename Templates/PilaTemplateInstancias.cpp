#include <PilaImplEstatica.cpp>
#include <PilaImplDinamica.cpp>
#include "Cadena.h"


template class PilaImplEstatica<float>;
template class PilaImplEstatica<Cadena>;

template class PilaImplDinamica<float>;
