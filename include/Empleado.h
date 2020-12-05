#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <Persona.h>


class Empleado : public Persona
{
private:
	unsigned legajo;
	Fecha fIngr;
	
public:
	Empleado();
	
	Empleado
	(
		unsigned dni,
		const Cadena& apellido,
		const Cadena& nombre,
		char sexo,
		const Fecha& fNac,
		unsigned legajo,
		const Fecha& fIngr
	);
	
	virtual ~Empleado();
	
	unsigned getLegajo();
	const Fecha& getFIngr();
	void setLegajo(unsigned legajo);
	void setFIngr(const Fecha& fIngr);
	virtual float calcularSueldo() = 0;
	
	friend ostream& operator <<(ostream& sal, const Empleado& empleado);
	friend istream& operator >>(istream& ent, Empleado& empleado);
	friend class EmpleadoBuilder;
};


#endif // EMPLEADO_H
