#include "Alumno.h"


Alumno::Alumno(int dni, const Cadena& apellido, const Cadena& nombres, char sexo, const Fecha& fechaNac, const Cadena& domicilio, const Cadena& nacionalidad, const Cadena& carrera, double promedio, int matricula, const Fecha& fechaIngr, int cantMatAprob)
: Persona(dni, apellido, nombres, sexo, fechaNac, domicilio, nacionalidad),
  carrera(carrera),	promedio(promedio), matricula(matricula), fechaIngr(fechaIngr), cantMatAprob(cantMatAprob)
{
	
}


const Cadena& Alumno::getCarrera() const
{
	return carrera;
}


double Alumno::getPromedio() const
{
	return promedio;
}


int Alumno::getMatricula() const
{
	return matricula;
}


const Fecha& Alumno::getFechaIngr() const
{
	return fechaIngr;
}


int Alumno::getCantMatAprob() const
{
	return cantMatAprob;
}


void Alumno::setCarrera(const Cadena& carrera)
{
	this->carrera = carrera;
}


void Alumno::setPromedio(double promedio)
{
	this->promedio = promedio;
}


void Alumno::setMatricula(int matricula)
{
	this->matricula = matricula;
}


void Alumno::setFechaIngr(const Fecha& fechaIngr)
{
	this->fechaIngr = fechaIngr;
}


void Alumno::setCantMatAprob(int cantMatAprob)
{
	this->cantMatAprob = cantMatAprob;
}


/******* Builder ********/

AlumnoBuilder::AlumnoBuilder()
: PersonaBuilder(), promedio(0), matricula(0), fechaIngr(1, 1, 1900), cantMatAprob(0)
{
}


void AlumnoBuilder::setCarrera(const Cadena& carrera)
{
	this->carrera = carrera;
}


void AlumnoBuilder::setPromedio(double promedio)
{
	this->promedio = promedio;
}


void AlumnoBuilder::setMatricula(int matricula)
{
	this->matricula = matricula;
}


void AlumnoBuilder::setFechaIngr(const Fecha& fechaIngr)
{
	this->fechaIngr = fechaIngr;
}


void AlumnoBuilder::setCantMatAprob(int cantMatAprob)
{
	this->cantMatAprob = cantMatAprob;
}


Alumno AlumnoBuilder::build() const
{
	return Alumno(dni, apellido, nombres, sexo, fechaNac, domicilio, nacionalidad, carrera, promedio, matricula, fechaIngr, cantMatAprob);
}


ostream& operator <<(ostream& sal, const Alumno& a)
{
	sal << (Persona&)a << '|' << a.carrera << '|' << a.promedio << '|' << a.matricula << '|' << a.fechaIngr << '|' << a.cantMatAprob;
	return sal;
}


istream& operator >>(istream& ent, Alumno& a)
{
	char campoStr[201];
	
	ent >> (Persona&)a;
	
	ent.getline(campoStr, 201, '|');
	a.carrera = (const char*)campoStr;
	
	ent >> a.promedio;
	ent.ignore(1);
	
	ent >> a.matricula;
	ent.ignore(1);
	
	ent >> a.fechaIngr;
	ent.ignore(1);
	
	ent >> a.cantMatAprob;
	ent.ignore(1);
	
	return ent;
}

