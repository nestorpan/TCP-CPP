#ifndef EMPLEADOEXTERNO_H
#define EMPLEADOEXTERNO_H

#include <iostream>

#include <Empleado.h>

using namespace std;


class EmpleadoExterno : public Empleado
{
private:
	float importeHora;
	int cantHorasTrabajadas;
	
public:
	EmpleadoExterno();
	
	float calcularSueldo();
	
	friend ostream& operator <<(ostream& sal, const EmpleadoExterno& emplExt);
	friend istream& operator >>(istream& ent, EmpleadoExterno& emplExt);
};


#endif // EMPLEADOEXTERNO_H
