#ifndef ALUMNOBUILDER_H
#define ALUMNOBUILDER_H

#include "PersonaBuilder.h"
#include "Alumno.h"


class AlumnoBuilder : public PersonaBuilder
{
private:
	Cadena carrera;
	Fecha fechaIngreso;
	double promedio;
	unsigned cantMatAprob;

public:
	AlumnoBuilder();

	AlumnoBuilder& setCarrera(const Cadena& carrera) { this->carrera = Alumno::validarCarrera(carrera); return *this; };
	AlumnoBuilder& setFechaIngreso(const Fecha& fechaIngreso) { this->fechaIngreso = Alumno::validarFechaIngreso(fechaIngreso); return *this; };
	AlumnoBuilder& setPromedio(double promedio) { this->promedio = Alumno::validarPromedio(promedio); return *this; };
	AlumnoBuilder& setCantMatAprob(unsigned cantMatAprob) { this->cantMatAprob = Alumno::validarCantMatAprob(cantMatAprob); return *this; };

	Alumno buildEstatica();
	Alumno* buildDinamica();
};


#endif // ALUMNOBUILDER_H
