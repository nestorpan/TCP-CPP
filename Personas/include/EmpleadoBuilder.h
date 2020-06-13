#ifndef EMPLEADOBUILDER_H
#define EMPLEADOBUILDER_H

#include "PersonaBuilder.h"
#include "Empleado.h"


class EmpleadoBuilder : public PersonaBuilder
{
	private:
		Fecha fechaIngr;
		Fecha fechaBaja;
		float sueldo;
		
	public:
		EmpleadoBuilder();
		
		void setFechaIngr(const Fecha& fechaIngr);
		void setFechaBaja(const Fecha& fechaBaja);
		void setSueldo(float sueldo);
		
		Empleado build();
};


#endif // EMPLEADOBUILDER_H
