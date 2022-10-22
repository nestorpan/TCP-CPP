#ifndef PERSONA_H
#define PERSONA_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"


class Persona
{
private:
	unsigned dni;
	Cadena apellido;
	Cadena nombre;
	Fecha fechaNacimiento;

	static unsigned validarDni(unsigned dni);
	static const Cadena& validarApellido(const Cadena& apellido);
	static const Cadena& validarNombre(const Cadena& nombre);

protected:
	Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento);

public:
	Persona();
	// Persona(const Persona& persona);
	// Persona& operator =(const Persona& persona);

	inline unsigned getDni() const { return dni; };
	inline void setDni(unsigned dni) { this->dni = validarDni(dni); };
	inline const Cadena& getApellido() const { return apellido; };
	inline void setApellido(const Cadena& apellido) { this->apellido = validarApellido(apellido); };
	inline const Cadena& getNombre() const { return nombre; };
	inline void setNombre(const Cadena& nombre) { this->nombre = validarNombre(nombre); };
	inline const Fecha& getFechaNacimiento() const { return fechaNacimiento; };
	inline void setFechaNacimiento(const Fecha& fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; };

	friend ostream& operator <<(ostream& os, const Persona& persona);
	friend istream& operator >>(istream& is, Persona& persona);

	friend class PersonaBuilder;
};


#endif // PERSONA_H
