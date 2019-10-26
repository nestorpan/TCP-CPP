#include "Alumno.h"


Alumno::Alumno()
: Persona(), cantMatAprob(0), promedio(0), matricula(0), fechaIngr(1, 1, 1900)
{
}


Alumno::Alumno(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo, const Cadena& domicilio, const Cadena& nacionalidad, int cantMatAprob, double promedio, int matricula, const Cadena& carrera,	const Fecha& fechaIngr)
: Persona(dni, apellido, nombres, fechaNac, sexo, domicilio, nacionalidad), cantMatAprob(cantMatAprob), promedio(promedio), matricula(matricula), carrera(carrera),	fechaIngr(fechaIngr)
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


/****** Builder *******/

AlumnoBuilder::AlumnoBuilder()
: PersonaBuilder(), cantMatAprob(0), promedio(0), matricula(0)
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
	return Alumno(dni, apellido, nombres, fechaNac, sexo, domicilio, nacionalidad, cantMatAprob, promedio, matricula, carrera, fechaIngr);
}
