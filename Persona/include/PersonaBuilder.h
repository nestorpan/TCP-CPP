#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../../Cadena/Cadena.h"
#include "../../Fecha/Fecha.h"
#include "Persona.h"


class PersonaBuilder
{
    private:
        unsigned dni;
        Cadena apyn;
        char sexo;
        Fecha fNac;
        char estadoCivil;
        Cadena email;


    public:
        PersonaBuilder();

        void setDni(unsigned dni);
        void setApyn(const Cadena& apyn);
        void setSexo(char sexo);
        void setFNac(const Fecha& fNac);
        void setEstadoCivil(char estadoCivil);
        void setEmail(const Cadena& email);

        Persona build();
};


#endif // PERSONABUILDER_H
