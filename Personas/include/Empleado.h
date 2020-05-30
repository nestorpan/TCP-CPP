#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <Persona.h>


class Empleado : public Persona
{
	private:
		Fecha fechaIngr;
		Fecha fechaBaja;
		float sueldo;
		
	public:
		Empleado(int dni = 0, const Cadena& apellido = "", const Cadena& nombres = "", const Fecha& fechaNac = Fecha(1, 1, 1601), char sexo = ' ', const Fecha& fechaIngr = Fecha(1, 1, 1601), const Fecha& fechaBaja = Fecha(1, 1, 1601), float sueldo = 0);
		
		const Fecha& getFechaIngr() const;
		void setFechaIngr(const Fecha& fechaIngr);
		
		const Fecha& getFechaBaja() const;
		void setFechaBaja(const Fecha& fechaBaja);
		
		float getSueldo() const;
		void setSueldo(float sueldo);
};


ostream& operator <<(ostream& sal, const Empleado& e);
istream& operator >>(istream& ent, Empleado& e);

#endif // EMPLEADO_H
