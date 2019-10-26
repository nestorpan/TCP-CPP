#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona
{
private:
	Cadena carrera;
	double promedio;
	int matricula;
	Fecha fechaIngr;
	int cantMatAprob;
	
public:
	Alumno(int dni, const Cadena& apellido, const Cadena& nombres, char sexo, const Fecha& fechaNac, const Cadena& domicilio, const Cadena& nacionalidad, const Cadena& carrera, double promedio, int matricula, const Fecha& fechaIngr, int cantMatAprob);
	
	const Cadena& getCarrera() const;
	double getPromedio() const;
	int getMatricula() const;
	const Fecha& getFechaIngr() const;
	int getCantMatAprob() const;
	void setCarrera(const Cadena& carrera);
	void setPromedio(double promedio);
	void setMatricula(int matricula);
	void setFechaIngr(const Fecha& fechaIngr);
	void setCantMatAprob(int cantMatAprob);
};


/******* Builder ********/

class AlumnoBuilder : public PersonaBuilder
{
private:
	Cadena carrera;
	double promedio;
	int matricula;
	Fecha fechaIngr;
	int cantMatAprob;
	
	
public:
	AlumnoBuilder();
	
	void setCarrera(const Cadena& carrera);
	void setPromedio(double promedio);
	void setMatricula(int matricula);
	void setFechaIngr(const Fecha& fechaIngr);
	void setCantMatAprob(int cantMatAprob);
	
	Alumno build() const;
};


#endif // ALUMNO_H
