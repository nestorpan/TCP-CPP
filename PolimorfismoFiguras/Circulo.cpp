#include "FiguraException.h"
#include "Circulo.h"

#define PI 3.1416


Circulo::Circulo(const Punto& p, double radio)
:p(p), radio(radio)
{
	if(radio <= 0)
		throw FiguraException("Circulo(): El radio no puede ser <= 0.");
}


double Circulo::perimetro() const
{
	return 2 * PI * radio;
}


double Circulo::area() const
{
	return PI * radio * radio;
}
