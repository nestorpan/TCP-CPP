#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include "Persona.h"


class Alumno : public Persona
{
private:
	int cantMatAprob;
	double promedio;
	int matricula;
	Cadena carrera;
	Fecha fechaIngr;
	
public:
	Alumno();
	Alumno(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo, const Cadena& domicilio, const Cadena& nacionalidad, int cantMatAprob, double promedio, int matricula, const Cadena& carrera,	const Fecha& fechaIngr);
	
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
	
	friend ostream& operator <<(ostream& sal, const Alumno& a);
	friend istream& operator >>(istream& ent, Alumno& a);
};


/****** Builder *******/

class AlumnoBuilder : public PersonaBuilder
{
private:
	int cantMatAprob;
	double promedio;
	int matricula;
	Cadena carrera;
	Fecha fechaIngr;
	
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
