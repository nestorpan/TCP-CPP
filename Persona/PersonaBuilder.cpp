#include "PersonaExc.h"
#include "PersonaBuilder.h"


PersonaBuilder::PersonaBuilder()
: dni("0"), nombre(""), apellido(""), fechaNacimiento(), sexo('X')
{}


PersonaBuilder& PersonaBuilder::setDni(const Cadena& dni)
{
    Persona::validarDNI(dni);
    this->dni = dni;
    return *this;
}


PersonaBuilder& PersonaBuilder::setNombre(const Cadena& nombre)
{
    this->nombre = nombre;
    return *this;
}


PersonaBuilder& PersonaBuilder::setApellido(const Cadena& apellido)
{
    this->apellido = apellido;
    return *this;
}


PersonaBuilder& PersonaBuilder::setFechaNacimiento(const Fecha& fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
    return *this;
}


PersonaBuilder& PersonaBuilder::setSexo(char sexo)
{
    this->sexo = sexo;
    return *this;
}


Persona PersonaBuilder::build()
{
    return Persona(dni, nombre, apellido, fechaNacimiento, sexo);
}
