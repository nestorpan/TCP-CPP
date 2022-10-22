#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona
{
private:
	Cadena carrera;
	Fecha fechaIngreso;
	double promedio;
	unsigned cantMatAprob;

	static const Cadena& validarCarrera(const Cadena& carrera);
	static const Fecha& validarFechaIngreso(const Fecha& fechaIngreso);
	static double validarPromedio(double promedio);
	static int validarCantMatAprob(int cantMatAprob);

protected:
	Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob);

public:
	Alumno();

	inline const Cadena& getCarrera() const { return carrera; };
	inline void setCarrera(const Cadena& carrera) { this->carrera = carrera; };
	inline const Fecha& getFechaIngreso() const { return fechaIngreso; };
	inline void setFechaIngreso(const Fecha& fechaIngreso) { this->fechaIngreso = fechaIngreso; };
	inline double getPromedio() const { return promedio; };
	inline void setPromedio(double promedio) { this->promedio = promedio; };
	inline unsigned getCantMatAprob() const { return cantMatAprob; };
	inline void setCantMatAprob(unsigned cantMatAprob) { this->cantMatAprob = cantMatAprob; };

	friend ostream& operator <<(ostream& os, const Alumno& alumno);
	friend istream& operator >>(istream& is, Alumno& alumno);
};

#endif // ALUMNO_H
