#ifndef EMPLEADOINTERNO_H
#define EMPLEADOINTERNO_H

#include <Empleado.h>


class EmpleadoInterno : public Empleado
{
private:
	float sueldo;
	
public:
	EmpleadoInterno();
	
	EmpleadoInterno
	(
		unsigned dni,
		const Cadena& apellido,
		const Cadena& nombre,
		char sexo,
		const Fecha& fNac,
		unsigned legajo,
		const Fecha& fIngr,
		float sueldo
	);
	
	float getSueldo();
	void setSueldo(float sueldo);
	float calcularSueldo();
	
	friend ostream& operator <<(ostream& sal, const EmpleadoInterno& emplInt);
	friend istream& operator >>(istream& ent, EmpleadoInterno& emplInt);
};


#endif // EMPLEADOINTERNO_H
