#include "Cuadrado.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Pentagono.h"
#include "FiguraFactory.h"


Figura* FiguraFactory::crearFigura(const Cadena& figuraStr)
{
	vector<Cadena> campos;
	figuraStr.split('|', campos);
	
	if(campos[0] == "Cuadrado")
		return new Cuadrado(campos[1].toDouble());
	
	if(campos[0] == "Circulo")
		return new Circulo(campos[1].toDouble());
	
	if(campos[0] == "Rectangulo")
		return new Rectangulo(campos[1].toDouble(), campos[2].toDouble());
	
	if(campos[0] == "Pentagono")
		return new Pentagono(campos[1].toDouble());
	
	throw string("El tipo solicitado no existe.");
}
