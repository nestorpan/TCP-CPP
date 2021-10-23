#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../Cadena/Cadena.h"
#include "Persona.h"

class PersonaBuilder
{
    private:
        int dni;
        Cadena apellido;
        Cadena nombre;
        char sexo;
        Fecha fNac;

    public:
        PersonaBuilder();

        void setDni(int dni);
        void setApellido(Cadena apellido);
        void setNombre(Cadena nombre);
        void setSexo(char sexo);
        void setFNac(Fecha fNac);

        Persona build() const;
        Persona buildMarta();
        Persona buildFemenino();

};

#endif // PERSONABUILDER_H
