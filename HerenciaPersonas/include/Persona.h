#ifndef PERSONA_H
#define PERSONA_H

#include <Cadena.h>
#include <Fecha.h>

class Persona
{
    private:
        unsigned dni;
        Cadena apellido;
        Cadena nombre;
        char sexo;
        Fecha fNac;

    protected:
        Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, char sexo, const Fecha& fNac);

    public:

        unsigned getDni() const;
        void setDni(unsigned dni);

        const Cadena& getApellido() const;
        void setApellido(const Cadena& apellido);

        const Cadena& getNombre() const;
        void setNombre(const Cadena& nombre);

        char getSexo() const;
        void setSexo(char sexo);

        const Fecha& getFNac() const;
        void setFNac(const Fecha& fNac);

        friend ostream& operator <<(ostream& sal, const Persona& pers);
        friend istream& operator >>(istream& ent, Persona& pers);

        friend class PersonaBuilder;
};

#endif // PERSONA_H
