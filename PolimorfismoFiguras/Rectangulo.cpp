#include "FiguraException.h"
#include "Triangulo.h"
#include "Rectangulo.h"


Rectangulo::Rectangulo(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4)
: p1(p1), p2(p2), p3(p3), p4(p4)
{
	if(!esRectangulo())
		throw FiguraException("Rectangulo(): Los puntos no forman un rectángulo.");
}


double Rectangulo::perimetro() const
{
	Punto perp1;
	Punto perp2;
	
	double distancia12 = p1 - p2;
	double distancia13 = p1 - p3;
	double distancia14 = p1 - p4;
	
	if(distancia12 > distancia13 && distancia12 > distancia14)
	{
		perp1 = p3;
		perp2 = p4;
	}
	else if(distancia13 > distancia12 && distancia13 > distancia14)
	{
		perp1 = p2;
		perp2 = p4;
	}
	else if(distancia14 > distancia12 && distancia14 > distancia13)
	{
		perp1 = p2;
		perp2 = p3;
	}
	
	return ((p1 - perp1) + (p1 - perp2)) * 2;
}


double Rectangulo::area() const
{
	Triangulo tr(p1, p2, p3);
	return tr.area() * 2;
}


bool Rectangulo::esRectangulo() const
{
	Punto opuesto;
	Punto perp1;
	Punto perp2;
	
	double distancia12 = p1 - p2;
	double distancia13 = p1 - p3;
	double distancia14 = p1 - p4;
	
	if(distancia12 > distancia13 && distancia12 > distancia14)
	{
		opuesto = p2;
		perp1 = p3;
		perp2 = p4;
	}
	else if(distancia13 > distancia12 && distancia13 > distancia14)
	{
		opuesto = p3;
		perp1 = p2;
		perp2 = p4;
	}
	else if(distancia14 > distancia12 && distancia14 > distancia13)
	{
		opuesto = p4;
		perp1 = p2;
		perp2 = p3;
	}
	
	double diag1 = p1 - opuesto;
	double diag2 = perp1 - perp2;
	
	return diag1 == diag2;
}
