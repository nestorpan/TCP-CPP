#include "Persona.h"

Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac)
:
	dni(Validaciones::mayorACero(dni, "DNI inválido")),
	apellido(Validaciones::letrasYEspacios(apellido, "Apellido inválido")),
	nombre(Validaciones::letrasYEspacios(nombre, "Nombre inválido")),
	sexo(Validaciones::sexo(), "Sexo invalido"),
	fNac(
      Validaciones::fechaMenorIgual(
            Validaciones::fechaMayorIgual(fNac, Fecha(1, 1, 1800), "Fecha Nac. muy antigua"),
                                Fecha::hoy(), "Fecha Nac. futura"))
{

}


unsigned Persona::getDni() const;
void Persona::setDni(unsigned dni);
const Cadena& Persona::getApellido() const;
void Persona::setApellido(const Cadena& apellido);
const Cadena& Persona::getNombre() const;
void Persona::setNombre(const Cadena& nombre);
char Persona::getSexo() const;
void Persona::setSexo();
const Fecha& Persona::getFNac() const;
void Persona::setFNac(const Fecha& fNac);
