#include "PersonaExc.h"
#include "Persona.h"


Persona::Persona()
{
    //ctor
}


Persona::Persona(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo)
{
    setDNI(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
    setSexo(sexo);
}


const Cadena& Persona::getDNI() const
{
    return dni;
}


void Persona::setDNI(const Cadena& dni)
{
    validarDNI(dni);
    this->dni = dni;
}


const Cadena& Persona::getNombre() const
{
    return this->nombre;
}


void Persona::setNombre(const Cadena& nombre)
{
    this->nombre = nombre;
}


const Cadena& Persona::getApellido() const
{
    return apellido;
}


void Persona::setApellido(const Cadena& apellido)
{
    this->apellido = apellido;
}


const Fecha& Persona::getFechaNacimiento() const
{
    return fechaNacimiento;
}


void Persona::setFechaNacimiento(const Fecha& fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}


char Persona::getSexo() const
{
    return sexo;
}


void Persona::setSexo(char sexo)
{
    this->sexo = sexo;
}


void Persona::validarDNI(const Cadena& dni)
{
    unsigned longMax = 8;

    if(dni[0] == 'M' || dni[0] == 'F')
    {
        longMax++;
        //TODO: validar que el resto de la cadena sea numerica
    }
    else
    {
        if(!dni.esEnteroPositivo())
        {
            throw PersonaExc("DNI invalido: " + dni + " no es un numero");
        }
    }


    if(dni.longitud() > longMax)
        throw PersonaExc("DNI invalido: " + dni + " supera la longitud maxima");
}
