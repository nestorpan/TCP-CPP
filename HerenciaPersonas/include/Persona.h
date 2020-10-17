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

    public:
        Persona(unsigned dni = 0, const Cadena& apellido = Cadena(), const Cadena& nombre = Cadena(),
                char sexo = 'M', const Fecha& fNac = Fecha());

        unsigned getDni() const;
        void setDni(unsigned dni);

        const Cadena& getApellido() const;
        void setApellido(const Cadena& apellido);

        const Cadena& getNombre() const;
        void setNombre(const Cadena& nombre);

        char getSexo() const;
        void setSexo();

        const Fecha& getFNac() const;
        void setFNac(const Fecha& fNac);
};

#endif // PERSONA_H
