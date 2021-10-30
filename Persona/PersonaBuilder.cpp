#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
: dni(0), sexo('X')
{}


void PersonaBuilder::setDni(int dni)
{
    this->dni = dni;
}


void PersonaBuilder::setApellido(Cadena apellido)
{
    this->apellido = apellido;
}


void PersonaBuilder::setNombre(Cadena nombre)
{
    this->nombre = nombre;
}


void PersonaBuilder::setSexo(char sexo)
{
    this->sexo = sexo;
}


void PersonaBuilder::setFNac(Fecha fNac)
{
    this->fNac = fNac;
}


Persona PersonaBuilder::build() const
{
    return Persona(dni, apellido, nombre, sexo, fNac);
}
