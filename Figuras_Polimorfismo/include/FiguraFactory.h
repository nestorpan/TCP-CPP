#ifndef FIGURAFACTORY_H
#define FIGURAFACTORY_H

#include <Cadena.h>
#include "Figura.h"


class FiguraFactory
{
	public:
		Figura* crearFigura(const Cadena& nombre);
};


#endif // FIGURAFACTORY_H
