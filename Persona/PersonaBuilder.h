#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "../Persona/Persona.h"


class PersonaBuilder
{
protected:
    Cadena dni;
    Cadena nombre;
    Cadena apellido;
    Fecha fechaNacimiento;
    char sexo;

public:
    PersonaBuilder();

    PersonaBuilder& setDni(const Cadena& dni);
    PersonaBuilder& setNombre(const Cadena& nombre);
    PersonaBuilder& setApellido(const Cadena& apellido);
    PersonaBuilder& setFechaNacimiento(const Fecha& fechaNacimiento);
    PersonaBuilder& setSexo(char sexo);

    Persona build();
};

#endif // PERSONABUILDER_H
