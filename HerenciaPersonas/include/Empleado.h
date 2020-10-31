#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <Persona.h>


class Empleado : public Persona
{
private:
	unsigned legajo;
	Fecha fIngr;
	float sueldo;
	
	Empleado
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
		
public:
	unsigned getLegajo();
	const Fecha& getFIngr();
	float getSueldo();
	void setLegajo(unsigned legajo);
	void setFIngr(const Fecha& fIngr);
	void setSueldo(float sueldo);
	
	friend ostream& operator <<(ostream& sal, const Empleado& empleado);
	friend istream& operator >>(istream& ent, Empleado& empleado);
	friend class EmpleadoBuilder;
};


#endif // EMPLEADO_H
